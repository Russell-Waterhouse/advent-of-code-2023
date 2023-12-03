/* 
 * DISCLAIMER: This is the very first C++ program that I've ever written
 */

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <fstream>


class Calibration { 
    public:
        int FindCalibration(std::vector<std::string> calibrations) { 
            std::vector<int> numbers {};
            char firstNum {};
            char lastNum {};

            for(std::string input: calibrations) {
                for(int i = 0; i < input.length(); i++) {
                    if(isdigit(input.at(i))) {
                        firstNum = input.at(i);
                        break;
                    }
                }

                for(int i = input.length() - 1; i >= 0; i--) {
                    if(isdigit(input.at(i))) {
                        lastNum = input.at(i);
                        break;
                    }
                }
                std::string number {firstNum, lastNum};

                numbers.push_back(std::stoi(number));
                std::cout << number << std::endl;
            }


            int sum = 0;
            for (auto x: numbers) {
                std::cout << "The number was: " << x << std::endl;
                sum += x;
            }

            std::cout << "The sum is: " << sum << std::endl;
            return sum;
        }
        
};

int main(int argc, char* argv[]) {
    std::cout << "Starting program" << std::endl;
    std::string inputFileName {argv[1]};
    std::ifstream inputFile(inputFileName);
    std::vector<std::string> rawInput {};
    std::string line {};
    while(std::getline(inputFile, line)) {
        if(line == "") {
            continue;
        }
        rawInput.push_back(line);
        std::cout << "Pushed back: " << line << std::endl;
    }
    inputFile.close();
    Calibration calibration {};
    calibration.FindCalibration(rawInput);

    std::cout << "End of program" << std::endl;
    return 0;
}
