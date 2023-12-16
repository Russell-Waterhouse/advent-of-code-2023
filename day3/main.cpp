#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;


class Coordinate {
    public:
        unsigned int x {0};
        unsigned int y {0};
        Coordinate(unsigned int xcoord, unsigned int ycoord) {
            x = xcoord;
            y = ycoord;
        }
};

bool IsSymbol(char character){
    return !isdigit(character) && character != '.';
}

int main(int argc, char* argv[]) {
    cout << "Hello" << endl;
    if(argc < 2) { 
        cout << "Not enough arguments" << endl;
    }
    string filename {argv[1]};
    ifstream inputFile(filename);
    string line{};
    std::vector<Coordinate> symbolCoordinates {};

    unsigned int lineNum = 0;
    unsigned int charNum = 0;
    while(std::getline(inputFile, line)) {
        charNum = 0;
        for (char c: line) {
            if (IsSymbol(c)) {
                Coordinate coordinate = Coordinate(lineNum, charNum);
                symbolCoordinates.push_back(coordinate);
                cout << "inserted coordinate" << coordinate.x << "," << coordinate.y << "For symbol " << c << endl;
            }
            charNum++;
        }
        cout << "LINE: " << line << endl;
        lineNum++;
    }
    inputFile.close();
    return 0;
}

