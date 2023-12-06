//Day 2: snow island challenge
//
// There are an unknown number of cubes in a bag, that are either red, green, or blue

#include <exception>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <regex>


using std::vector;
using std::cout;
using std::endl;



class DicePull { 
public: 
    int red;
    int green;
    int blue;
    DicePull(int red_pull, int green_pull, int blue_pull){ 
        red = red_pull;
        green = green_pull;
        blue = blue_pull;
    }

    bool Possible() {
        return red <= 12 && green <= 13 && blue <= 14;
    }
};


class Game {
public: 
    int gameNumber;
    vector<DicePull> dice_pulls;

    Game(std::string game_input) {
        this->dice_pulls = {};
        //first, set the game number correctly
        size_t pos = game_input.find(':');
        std::string game_number = game_input.substr(0, pos);
        game_number = game_number.substr(5);
        this->gameNumber = std::stoi(game_number);

        if(this->gameNumber > 100) {
            throw std::exception();
        }

        //then, set the pulls
        std::string pulls_substring = game_input.substr(pos);
        pos = pulls_substring.find(';');
        int i = 0;
        pulls_substring.append(";  "); // append '; 'so iteration stops correctly
        while(pulls_substring.find(';') != std::string::npos) {
            i ++;
            pos = pulls_substring.find(';');
            std::string working_substring = pulls_substring.substr(0, pos);
            pulls_substring = pulls_substring.substr(pos + 2);

            std::regex patternRed("\\b(\\d+)\\b red");
            std::regex patternGreen("\\b(\\d+)\\b green");
            std::regex patternBlue("\\b(\\d+)\\b blue");
            std::smatch redMatch;
            std::smatch greenMatch;
            std::smatch blueMatch;
            int red = 0;
            int green = 0;
            int blue = 0;
            if (std::regex_search(working_substring, redMatch, patternRed)) {
                red = std::stoi(redMatch[1].str());
            }
            if (std::regex_search(working_substring, greenMatch, patternGreen)) {
                green = std::stoi(greenMatch[1].str());
            }
            if (std::regex_search(working_substring, blueMatch, patternBlue)) {
                blue = std::stoi(blueMatch[1].str());
            }
            this->dice_pulls.push_back(DicePull(red, green, blue));
            if (i >=20){
                throw std::exception();
            }
        }
    }

    bool Possible() {
        bool possible = true;
        for (DicePull pull : this->dice_pulls) {
            possible = possible && pull.Possible();
        }
        return possible;
    }

    unsigned int MinPower() {
        unsigned int min_red = 0;
        unsigned int min_green = 0;
        unsigned int min_blue = 0;
        for (DicePull pull : this->dice_pulls) {
            if(pull.red > min_red) {
                min_red = pull.red;
            }
            if(pull.green > min_green) {
                min_green = pull.green;
            }
            if(pull.blue > min_blue) {
                min_blue = pull.blue;
            }
        }
        cout << "minRGB: " << min_red << ";" << min_green << ";" << ";" << min_blue << endl;
        unsigned int power = 1;
        if (min_red != 0) {
            power *= min_red;
        }
        if (min_green != 0) {
            power *= min_green;
        }
        if (min_blue != 0) {
            power *= min_blue;
        }
        return power;
    }
};


int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "No argument given, exiting" << endl;
        return 0;
    }
    std::string input_file_name = {argv[1]};
    std::ifstream inputFile(input_file_name);
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

    vector<Game> possible_games {};
    vector<Game> all_games {};
    for (std::string line : rawInput) {
        Game game = Game(line);
        if(game.Possible()) {
            possible_games.push_back(game);
        }
        all_games.push_back(game);
    }

    unsigned int id_sum = 0;
    for(Game game: possible_games) {
        id_sum += game.gameNumber;
    }
    std::cout << "The id sum of possible games is: " << id_sum << std::endl;


    unsigned int power_sum = 0;
    for(Game game: all_games) {
        power_sum += game.MinPower();
    }

    std::cout << "The power sum of possible games is: " << power_sum << std::endl;

    return 0;
}
