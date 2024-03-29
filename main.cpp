#include <iostream>
#include <cstdlib>
#include <ctime>

class Randomizer {
public:
    static std::string getLowercaseLetter() {
        int randomIdx = rand() % 26;
        char randomLetter = 'a' + randomIdx;
        // std::cout << std::string (1, randomLetter) << std::endl;
        return std::string (1, randomLetter);
    }

    static std::string getUppercaseLetter() {
        int randomIdx = rand() % 26;
        char randomLetter = 'A' + randomIdx;
        // std::cout << std::string (1, randomLetter) << std::endl;
        return std::string (1, randomLetter);

    }

    static std::string getSpecialChar() {
        const char specialChar[] = "!@#$%^&*()_+}{[]<>?/|";
        const int length = sizeof(specialChar) - 1;
        int randomIdx = rand() % length;
        // std::cout << std::string (1, specialChar[randomIdx]) << std::endl;
        return std::string (1, specialChar[randomIdx]);
    }

    static std::string getNumber(){
        // std::cout << std::to_string (rand() % 11) << std::endl;
        return std::to_string (rand() % 11);

    };
};

typedef std::string (*MethodList)();

int main() {
    srand(time(NULL));

    int length;
    std::string password;

    std::cout << "\nEnter the length of your password: "<< std::endl;
    std::cin >> length;
    MethodList randomMethods[] = {Randomizer::getLowercaseLetter, Randomizer::getUppercaseLetter,
                            Randomizer::getNumber, Randomizer::getSpecialChar};

    for (int i = 0; i < length; i++) {
        int randomIdx = rand() % (sizeof(randomMethods) / sizeof(randomMethods[0]));
        std::string tempPwd = (randomMethods[randomIdx])();
        password += tempPwd;
    }

    std::cout << "\nYour password is: " << password << std::endl;

    return 0;
}
