#include <iostream>
#include <unordered_set>
#include <string>

class FindRepeatDigitCount {
private:
    int number;
public:
    FindRepeatDigitCount(int no) {
        number = no;
    }

    void findRepeatDigit() {
        std::string numStr = std::to_string(number);
        std::unordered_set<char> seen;
        std::string result;

        for (char digit : numStr) {
            if (seen.count(digit) == 0) {
                seen.insert(digit);
            } else if (result.find(digit) == std::string::npos) {
                result += digit;
            }
        }

        if (!result.empty()) {
            std::cout << "Repetitive digits: " << result << std::endl;
        } else {
            std::cout << "No repetitive digits found." << std::endl;
        }
    }

    void show() {
        std::cout << "Number: " << number << std::endl;
    }
};

int main() {
    int inputNumber = 1453134;
    FindRepeatDigitCount obj(inputNumber);

    obj.show();
    obj.findRepeatDigit();

    return 0;
}