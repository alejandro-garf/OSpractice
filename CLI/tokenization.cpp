#include <iostream>
#include <vector>
#include <string>


using namespace std;
int main()
{
    char buffer[8192];

    cout << "Enter your prompt" << endl;
    cout << "==> ";

    cin.getline(buffer, 8192);

    string command = buffer;
    vector<string> parts;
    string currentPart = "";

    for (int i = 0; i < command.length(); i++)
    {
        char c = command[i];

        if (c == ' ')
        {
            if (currentPart.length() > 0)
            {
                parts.push_back(currentPart);
                currentPart = "";
            }
        } 
        else 
        {
            currentPart += c;
        }
    }

    if (currentPart.length() > 0)
    {
        parts.push_back(currentPart);
        currentPart = "";
    }

    cout << "Here is what you typed: " << endl;
    for (int i = 0; i < parts.size(); i++)
    {
        string print = parts[i];
        cout << print << endl;
    }
    



    return 0;
}