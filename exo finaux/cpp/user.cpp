#include "user.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

User::User(int id, const Password& pwd)
    : id(id), password(std::make_unique<Password>(pwd)) {}

void User::save() const {
    sqlite3* db;
    if (sqlite3_open("user.db", &db) != SQLITE_OK) {
        throw std::runtime_error("Erreur d'ouverture de la base de données");
    }

    const char* create_table = "CREATE TABLE IF NOT EXISTS users (id INT PRIMARY KEY, password TEXT);";
    sqlite3_exec(db, create_table, nullptr, nullptr, nullptr);

    std::ostringstream query;
    query << "INSERT OR REPLACE INTO users (id, password) VALUES ("
          << id << ", '" << password->str() << "');";
    sqlite3_exec(db, query.str().c_str(), nullptr, nullptr, nullptr);

    sqlite3_close(db);
}

User User::get(int id) {
    sqlite3* db;
    if (sqlite3_open("user.db", &db) != SQLITE_OK) {
        throw std::runtime_error("Erreur d'ouverture de la base de données");
    }

    std::ostringstream query;
    query << "SELECT password FROM users WHERE id = " << id << ";";

    Password pwd("invalid");
    sqlite3_exec(db, query.str().c_str(),
        [](void* pwd_ptr, int argc, char** argv, char** col_names) -> int {
            if (argc > 0 && argv[0]) {
                *reinterpret_cast<Password*>(pwd_ptr) = Password(argv[0], true);
            }
            return 0;
        },
        &pwd, nullptr);

    sqlite3_close(db);

    return User(id, pwd);
}

int User::login(int id, const std::string& raw_password) const {
    return *password == raw_password ? 1 : 0;
}
