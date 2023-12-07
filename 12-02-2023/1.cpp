#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

map<string, int> buildmap() {
    return {
    {"red", 12}, {"green", 13}, {"blue", 14}
    };
}

enum Curr { NONE, NUM, ID, COL };

int main() {
    map<string, int> colors = buildmap();

    ifstream input("input");
    
    string word;
    Curr curr = NONE;
    bool possible = true;
    unsigned int result = 0;
    unsigned int id = 0;
    unsigned int count = 0;

    while (getline(input, word)) {
        stringstream line(word);
        
        while (getline(line, word, ' ')) {
            if (curr == NONE && word[0] == 'G') {
                curr = ID;

                if (possible) result += id;
                possible = true;
                continue;
            }

            istringstream iss(word);

            switch (curr) {
                case ID:
                    iss >> id;
                    curr = NUM;
                    break;
                case COL:
                    switch (word.back()) {
                        case ';':
                        case ',':
                            word.pop_back();
                            curr = NUM;
                            break;
                        default:
                            curr = NONE;
                    }
                    if (count > colors.at(word))
                        possible = false;
                    break;
                case NUM:
                    iss >> count;
                    curr = COL;
                    break;
                default:
                    break;
            }
        }
    }
    
    if (possible) result += id;
    ofstream output("output1");
    input.close();
    output << result;
    output.close();

}
