#ifndef USER_HPP
#define USER_HPP

#include "password.hpp"
#include <memory>
#include <sqlite3.h>

class User {
private:
    int id;
    std::unique_ptr<Password> password; // Gestion sécurisée du mot de passe

public:
    User(int id, const Password& password);

    void save() const; // Sauvegarde dans la base de données
    static User get(int id); // Récupération depuis la base de données
    int login(int id, const std::string& raw_password) const; // Connexion
};

#endif
