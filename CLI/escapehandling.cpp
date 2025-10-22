#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> parts = {"echo", "Hello there", "yip \\ \" pee", "yay"};
    string result = "";

    for (int i = 0; i < parts.size(); i++) {
        if (i > 0) {
            result += " ";
        }

        bool needQuotes = (i > 0);
        if (needQuotes) {
            result += "\"";
        }

        string currentPart = parts[i];
        for (int j = 0; j < currentPart.length(); j++) {
            char c = currentPart[j];

            if (c == '"' || c == '\\') {
                result += "\\";
            }

            result += c;
        }

        if (needQuotes) {
            result += "\"";
        }
    }

    cout << "Rebuilt command: " << result << endl;
    return 0;
}
