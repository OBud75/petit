#include "password.hpp"

int main()
{
    // Test the Password class
    auto password = std::make_unique<Password>("123456");
    std::cout << password->str() << std::endl;

    auto password2 = std::make_unique<Password>("123456", true);
    std::cout << password2->str() << std::endl;

    if (password == password2){
        std::cout << "Passwords are the same" << std::endl;
    } else {
        std::cout << "Passwords are different" << std::endl;
    }

    const std::string p = "123456";
    if (password == p){
        std::cout << "Passwords are the same" << std::endl;
    } else {
        std::cout << "Passwords are different" << std::endl;
    }

    return 0;
}
