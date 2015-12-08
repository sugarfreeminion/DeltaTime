#include <iostream>
#include <fstream>

using namespace std;

/*
 * Function Name:   ParseInput
 * Description:     parses the input string based on a space between two times
 */
void ParseInput(string input, string& initTime, string& finalTime)
{
    unsigned int index = 0;

    bool foundSpace = false;

    while(index < input.length())
    {
        if(input[index] != ' ' && input[index] != '\n')
        {
            if(foundSpace == false)
            {
                initTime = initTime + input[index];
            }
            else
            {
                finalTime = finalTime + input[index];
            }
        }
        else if(input[index] == ' ')
        {
            foundSpace = true;
        }

        ++index;
    }

    cout << "    Initial Time: " << initTime << "    Final Time: " << finalTime << endl;
}

int main(int argc, char *argv[])
{
    ifstream inputFile(argv[1]);

    string input;

    if(inputFile.is_open())
    {
        while(getline(inputFile,input))
        {
            string initTime;
            string finalTime;

            cout << input << endl;

            ParseInput(input,initTime,finalTime);
        }
    }
    else
    {
        cout << "Input File error" << endl;
    }

    return 0;
}
