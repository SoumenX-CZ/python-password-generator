#include <iostream>
#include <cstdlib>
#include <ctime>

std::string generatePassword(int length) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    std::string password;
    
    std::srand(std::time(nullptr));

    for (int i = 0; i < length; ++i) {
        password += characters[std::rand() % characters.length()];
    }

    return password;
}

int main() {
    int length;
    std::cout << "Zadejte délku hesla: ";
    std::cin >> length;

    std::string password = generatePassword(length);
    std::cout << "Generované heslo: " << password << std::endl;

    return 0;
}