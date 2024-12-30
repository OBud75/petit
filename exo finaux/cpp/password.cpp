#include "password.hpp"
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <cstring>
#include <algorithm>

// Constructeur
Password::Password(const std::string& password, bool is_encrypted) {
    if (is_encrypted) {
        decode_hex(password);  // Décoder la chaîne hexadécimale
    } else {
        encrypt(password);  // Chiffrer le mot de passe
    }
}

// Méthode pour chiffrer un mot de passe (SHA-1)
void Password::encrypt(const std::string& password) {
    SHA1(reinterpret_cast<const unsigned char*>(password.c_str()), password.size(), _encrypted_value.data());
}

// Méthode pour décoder un mot de passe hexadécimal en binaire
void Password::decode_hex(const std::string& hex_str) {
    if (hex_str.size() != SHA_DIGEST_LENGTH * 2) {
        throw std::invalid_argument("Longueur incorrecte pour un mot de passe crypté");
    }

    for (size_t i = 0; i < SHA_DIGEST_LENGTH; ++i) {
        std::string byte_str = hex_str.substr(i * 2, 2);
        _encrypted_value[i] = static_cast<unsigned char>(std::stoi(byte_str, nullptr, 16));
    }
}

// Retourne une chaîne hexadécimale du hachage
std::string Password::str() const {
    std::ostringstream oss;
    for (unsigned char byte : _encrypted_value) {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
    }
    return oss.str();
}

// Comparaison avec une chaîne
bool Password::operator==(const std::string& str) const {
    Password temp(str, false);  // Créer un mot de passe à partir de la chaîne
    return _encrypted_value == temp._encrypted_value;
}

// Comparaison avec un autre mot de passe
bool Password::operator==(const Password& other) const {
    return _encrypted_value == other._encrypted_value;
}

// Surcharge de l'opérateur de flux
std::ostream& operator<<(std::ostream& os, const Password& p) {
    os << p.str();
    return os;
}
