/* 
 * DISCLAIMER: This is the very first C++ program that I've ever written
 */

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <fstream>
#include <unordered_map>


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

        std::vector<std::string> fixForPart2(std::vector<std::string> calibrations) {
            std::vector<std::string> fixedCalibrations {};

            for(std::string calibration: calibrations) { 
                std::string replacement = replaceNumericalStrings(calibration);
                std::cout << "Replaced: " << calibration << " with: " << replacement << std::endl;
                fixedCalibrations.push_back(replacement);
            }

            return fixedCalibrations;
        }

        std::string replaceNumericalStrings(std::string input) {
            std::unordered_map<std::string, std::string> replacements {};
            replacements["one"] = "1";
            replacements["two"] = "2";
            replacements["three"] = "3";
            replacements["four"] = "4";
            replacements["five"] = "5";
            replacements["six"] = "6";
            replacements["seven"] = "7";
            replacements["eight"] = "8";
            replacements["nine"] = "9";

            std::string replacement = input;
            for(const auto& replacementPair: replacements) {
                auto key = replacementPair.first;
                auto value = replacementPair.second;

                auto position = replacement.find(key);
                if(position != std::string::npos) {
                    replacement = replacement.replace(position, key.length(), value);
                }
                //position = replacement.find_last_of(key);
                //if(position != std::string::npos) {
                    //replacement = replacement.replace(position, key.length(), value);
                //}
            }
            return replacement;
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

    std::vector<std::string> inputCleanedForPart2 = calibration.fixForPart2(rawInput);

    calibration.FindCalibration(inputCleanedForPart2);

    std::cout << "End of program" << std::endl;
    return 0;
}
