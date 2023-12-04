#include <iostream>
#include <cctype>
#include <string>
#include <fstream>

using namespace std;

int main() {
    unsigned int result = 0;
    string line;

    ifstream file("input");
    ofstream output("output");

    while (getline(file, line)) {
        for (int i = 0; i < (int) line.size(); i++) {
            if (isdigit(line[i])) {
                result += 10 * (line[i] - '0');
                break;
            }
        }
        for (int i = (int) line.size() - 1; i >= 0; i--) {
            if (isdigit(line[i])) {
                result += line[i] - '0';
                break;
            }
        }
    }
    file.close();
    output << result << endl; 
    output.close();
    return 0;
}
