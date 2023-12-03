/* 
 * DISCLAIMER: This is the very first C++ program that I've ever written
 */

#include <exception>
#include <iostream>
#include <vector>
#include <cctype>
#include <fstream>
#include <unordered_map>
#include <optional>


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

        int part2(std::vector<std::string> input) {
            return 0;
        }

        std::string firstNumberInString(std::string) {
            int substringSize = 0;
            //TOOD: iterate through string, taking larger and larger substring slices until numberInString returns nonempty optional
            return "";
        }


        std::optional<std::string> numberInString(std::string input) {
            std::unordered_map<std::string, std::string> numbers {};
            numbers["0"] = "0";
            numbers["1"] = "1";
            numbers["2"] = "2";
            numbers["3"] = "3";
            numbers["4"] = "4";
            numbers["5"] = "5";
            numbers["6"] = "6";
            numbers["7"] = "7";
            numbers["8"] = "8";
            numbers["9"] = "9";
            numbers["one"] = "1";
            numbers["two"] = "2";
            numbers["three"] = "3";
            numbers["four"] = "4";
            numbers["five"] = "5";
            numbers["six"] = "6";
            numbers["seven"] = "7";
            numbers["eight"] = "8";
            numbers["nine"] = "9";
            for(std::pair<std::string, std::string> numberPair: numbers) {
                auto foundNumberIndex = input.find(numberPair.first);
                if(foundNumberIndex != std::string::npos) {
                    return std::optional(numberPair.second);
                }
            }
            return std::nullopt;
        }
};

int main(int argc, char* argv[]) {
    std::cout << "Starting program" << std::endl;
    if (argc < 2) {
        std::cout << "No argument" << std::endl;
        return -1;
    }
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

    int calibrationPart2 = calibration.part2(rawInput);
    std::cout << "The final calibration value is: " << calibrationPart2 << std::endl;

    std::cout << "End of program" << std::endl;
    return 0;
}
