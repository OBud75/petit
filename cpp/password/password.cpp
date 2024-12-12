#include "password.hpp"

Password::Password(const std::string &pass, bool is_encrypted) : _raw_value(pass) {
    // verify if the password is strong
    
    // verify if the password is already encrypted
    if (is_encrypted) {
        _encrypted_value = pass;
    } else {
        encrypt(pass);
    }
};

void Password::encrypt(const std::string &password) {
    _encrypted_value.resize(password.size());
    for (char c : password) {
        _encrypted_value.push_back(c ^ 'K');
    }
};

std::string Password::str() {
    return _encrypted_value;
};

bool Password::operator ==(const std::string &str) const {
    return _encrypted_value == str;
};

bool Password::operator ==(const Password &other) const {
    return _encrypted_value == other._encrypted_value;
};

std::ostream &operator<<(std::ostream &os, const Password &p) {
    os << p._encrypted_value;
    printf("Password: %s", p._encrypted_value);
    return os;
};

bool Password::is_valid(std::string &password) {
    // verify if the password is strong
    if(password.size() < 12) throw std::runtime_error("Password is too short");
    if(password.size() > 18) throw std::runtime_error("Password is too long");
    if(password.find_first_of("0123456789") == std::string::npos) throw std::runtime_error("Password must contain at least one digit");
    if(password.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos) throw std::runtime_error("Password must contain at least one uppercase letter");
    if(password.find_first_of("abcdefghijklmnopqrstuvwxyz") == std::string::npos) throw std::runtime_error("Password must contain at least one lowercase letter");
    if(password.find_first_of("!@#$%^&*") == std::string::npos) throw std::runtime_error("Password must contain at least one special character");
    return true;
};