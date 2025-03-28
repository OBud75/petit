#include "user.hpp"
#include <cassert>
#include <iostream>

int main() {
    try {
        // Création d'un utilisateur avec un mot de passe
        Password pwd("toto", false);
        User user(1, pwd);

        // Test de la méthode Password::str (mot de passe crypté)
        std::string encrypted_pwd = pwd.str();
        std::cout << "Mot de passe crypté : " << encrypted_pwd << std::endl;
        assert(!encrypted_pwd.empty());

        // Sauvegarde de l'utilisateur dans la base de données
        user.save();
        std::cout << "Utilisateur sauvegardé dans la base de données." << std::endl;

        // Récupération de l'utilisateur depuis la base de données
        User retrieved_user = User::get(1);
        assert(retrieved_user.login(1, "toto") == 1);
        std::cout << "Connexion réussie avec le mot de passe correct." << std::endl;

        // Test de la connexion avec un mot de passe incorrect
        assert(retrieved_user.login(1, "wrong_password") == 0);
        std::cout << "Connexion échouée avec un mot de passe incorrect." << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
// On évite d'englober tout le code dans 1 seul try/catch
// Le code qui ne peut pas lever d'exception comme les std::cout n'a rien à y faire
// En faisant des try/catch très ciblés on arrive mieux à detecter ce qui pose problème

// Pas forcément besoin d'ajouter les commentaires à chaque ligne, cela rajoute de la maintenance
// si le code change (et on prend le risque qu'il ne soit pas à jour et donc "mente" sur le code)