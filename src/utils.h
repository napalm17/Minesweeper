#include <random>

struct Utils
{
    static int getRandomInteger(int min, int max) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distr(min, max);
        return distr(gen);
    }


    static int parseSingleInt(std::string str) {
        int value;
        std::cout << "Enter " + str + ":";
        if (!(std::cin >> value)) {
            throw std::invalid_argument("Invalid input. Please enter a valid integer.");
        }
        return value;
    }

    static std::string parseCommand() {
        std::string input;
        std::cout << "Mark or reveal (m/r): ";
        std::cin >> input;
        return input;
}
};


