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
    // Il pourrait être interessant de renvoyer un pointeur/référence vers l'user (créé avec new pour allouer de la mémoire sur le tas comme malloc)
    // Dans les faits on préfère souvent renvoyer une copie comme vous l'avez fait que d'avoir à gérer la libération de la mémoire.
    // On peut par contre utiliser des smart pointers, ici à piori make_unique<User>(id, pwd)
    // On peut éventuellement utiliser std::move pour éviter la copie de l'autre côté du return.

    // Une autre solution serait d'utiliser un conteneur de pointeurs uniques d'User
    // std::vector<std::unique_ptr<User>>
    // La fonction get pourrait donc checker dans ce conteneur si un des users à l'id et renvoyer cet user,
    // sinon le créer, l'ajouter au conteneur (qui récupère donc la responsabilité de free la mémoire)
    // et renvoyer l'instance qu'on vient d'ajouter au conteneur.

    // Ca rejoint les concepts d'object lifetime et d'ownership en rust
}

int User::login(int id, const std::string& raw_password) const {
    return *password == raw_password ? 1 : 0;
}
