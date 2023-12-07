#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

enum Curr { NONE, NUM, ID, COL };

int main() {
    map<string, int> colors = {
        {"red", 0}, {"green", 0}, {"blue", 0}
    };

    ifstream input("input");
    
    string word;
    Curr curr = NONE;
    unsigned int result = 0;
    unsigned int id = 0;
    unsigned int count = 0;

    while (getline(input, word)) {
        stringstream line(word);
        
        while (getline(line, word, ' ')) {
            if (curr == NONE && word[0] == 'G') {
                curr = ID;
                int pow = 1;
                for (auto item: colors) {
                    pow *= item.second;
                    colors[item.first] = 0;
                }
                result += pow;
                continue;
            }

            istringstream iss(word);

            switch (curr) {
                case ID:
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
                    if (count > colors[word])
                        colors[word] = count;
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
    
    int pow = 1;
    for (auto item: colors) {
        pow *= item.second;
    }
    result += pow;
    ofstream output("output2");
    input.close();
    output << result;
    output.close();

}
