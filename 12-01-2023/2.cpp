#include <fstream>
#include <cctype>
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> getMap() {
    return {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
    };
}

int main() {
    unsigned int result = 0;
    ifstream input("input");
    ofstream output("output2");
    string line;

    auto digitMap = getMap();

    if (!input.is_open() || !output.is_open()) {
        cerr << "Error opening files" << endl;
        return 1;
    }

    while (getline(input, line)) {
        bool first = false;
        int last_number = 0;

        for (int i = 0; i < (int) line.size(); i++) {
            if (isdigit(line[i])) {
                if (!first) {
                    result += 10 * (line[i] - '0');
                    first = true;
                }
                last_number = line[i] - '0';
            } else {
                int temp = 0;
                for (auto &[key, value] : digitMap) {
                    if (line.substr(i, key.size()) == key) {
                        temp = value;
                        break;
                    }
                }

                if (temp == 0) {
                    continue;
                }

                if (!first) {
                    result += 10 * temp;
                    first = true;
                }
                last_number = temp;
            }
        }

        result += last_number;
    }

    input.close();
    output << result << endl;
    output.close();
}
