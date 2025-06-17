#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>

std::string generatePassword(int length) {
    const std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string numbers = "0123456789";
    const std::string symbols = "!@#$%^&*()_-+=<>?/{}[]|";

    const std::string allChars = lowercase + uppercase + numbers + symbols;
    std::string password;

    std::srand(std::time(nullptr));

    password += lowercase[std::rand() % lowercase.length()];
    password += uppercase[std::rand() % uppercase.length()];
    password += numbers[std::rand() % numbers.length()];
    password += symbols[std::rand() % symbols.length()];

    for (int i = 4; i < length; ++i) {
        password += allChars[std::rand() % allChars.length()];
    }

    return password;
}

int evaluateStrength(const std::string& password) {
    bool hasLower = false, hasUpper = false, hasDigit = false, hasSymbol = false;

    for (char ch : password) {
        if (std::islower(ch)) hasLower = true;
        if (std::isupper(ch)) hasUpper = true;
        if (std::isdigit(ch)) hasDigit = true;
        if (std::ispunct(ch)) hasSymbol = true;
    }

    int score = (hasLower + hasUpper + hasDigit + hasSymbol) * 2 + (password.length() >= 12 ? 4 : 0);
    return score;
}

int main() {
    int length;
    std::cout << "Zadej délku hesla: ";
    std::cin >> length;

    if (length < 6) {
        std::cout << "Heslo by mělo mít alespoň 6 znaků pro základní bezpečnost!\n";
        return 1;
    }

    std::string password = generatePassword(length);
    std::cout << "Vygenerované heslo: " << password << std::endl;

    int strength = evaluateStrength(password);
    std::cout << "Síla hesla: ";

    if (strength >= 8) std::cout << "Velmi silné\n";
    else if (strength >= 6) std::cout << "Silné\n";
    else if (strength >= 4) std::cout << "Střední\n";
    else std::cout << "Slabé\n";

    return 0;
}