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
    bool quoting = false; // initally turned off


    // Loop for the actrual parisng 
    for (int i = 0; i < command.length(); i++)
    {
        char c = command[i];

        if(c == '"')
        {
            quoting = !quoting; //turns on quoting mode when "" is detected.
            continue;
        }

        //Handling for when we see a space 
        if (c == ' ')
        {
            if (!quoting) //if quotiing is turned off
            {
                if (currentPart.length() > 0)
                {
                parts.push_back(currentPart);
                currentPart = "";
                }
            }
            else // if quoting is still turned on.
            {
                currentPart += c;
            }
        } 
        else 
        {
            currentPart += c;
        }
    }

    if (quoting) // if quoting is still turned on.
    {
        perror("You did not add an ending quote!");
        cout << endl;
        return 1;
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