#include <string>
#include <stdexcept>
#include <memory>
#include <iostream>

class Password {
    private:
        std::string _raw_value;
        std::string _encrypted_value;
        void encrypt(const std::string &pass);

    public:
        Password(const std::string &pass, bool is_encrypted=false);
        std::string str();

        bool is_valid(std::string &password);
        bool operator ==(const std::string &str) const;
        bool operator ==(const Password &other) const;
        friend std::ostream &operator<<(std::ostream &os, const Password &p);
};