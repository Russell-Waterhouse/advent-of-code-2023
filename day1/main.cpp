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
#include <string>


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
            int sum = 0;
            for(std::string line: input) {
                std::string first = firstNumberInString(line);
                std::string last = lastNumberInString(line);
                std::cout << first << " + " << last << std::endl;
                std::string combined = first + last;
                sum += std::stoi(combined);
            }
            return sum;
        }

        std::string firstNumberInString(std::string input) {
            std::string substring;
            for(int i = 0; i <= input.size(); i++) {
                substring = input.substr(0, i);
                std::optional<std::string> firstNumber = numberInString(substring);
                if (firstNumber.has_value()) {
                    return firstNumber.value();
                }
            }
            std::cout << "Throwing in first number case" << std::endl;
            throw std::exception();
        }

        std::string lastNumberInString(std::string input) {
            std::string substring; 
            for(int i = input.size() - 1; i >=0; i--) {
                substring = input.substr(i);
                std::optional<std::string> lastNumber = numberInString(substring);
                if (lastNumber.has_value()) {
                    return lastNumber.value();
                }
            }
            std::cout << "Throwing in last number case" << std::endl;
            throw std::exception();
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
