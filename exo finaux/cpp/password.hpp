#ifndef PASSWORD_HPP
#define PASSWORD_HPP

#include <array>
#include <string>
#include <iostream>
#include <openssl/sha.h>

class Password {
private:
    std::array<unsigned char, SHA_DIGEST_LENGTH> _encrypted_value; // Valeur binaire du mot de passe
    void encrypt(const std::string& password); // Méthode de hachage
    void decode_hex(const std::string& hex_str); // Méthode pour décoder un mot de passe hexadécimal

public:
    Password(const std::string& password, bool is_encrypted = false); // Constructeur

    std::string str() const; // Représentation hexadécimale
    bool operator==(const std::string& str) const;
    bool operator==(const Password& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Password& p);
};

#endif
