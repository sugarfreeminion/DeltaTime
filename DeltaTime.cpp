#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

/*
 * Function Name:   ParseInput
 * Description:     parses the input string based on a space between two times
 */
void ParseInput(string input, string &initTime, string &finalTime)
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
}

/*
 * Function Name:   ConvertToSeconds
 * Description:     converts time in HH:MM:SS format to total seconds
 */
unsigned int ConvertToSeconds(string time)
{
    unsigned int totalSeconds = 0;
    unsigned int index = 0;

    unsigned int prevDelimiter = 0;
    unsigned int currDelimiter = 0;
    unsigned int hmsLength = 0;

    bool foundHour = false;
    bool foundMin = false;
    bool foundSec = false;

    while(index <= time.length())
    {
        if(time[index] == ':' || index == time.length())
        {
            currDelimiter = index;

            hmsLength = currDelimiter - prevDelimiter;

            // Debug messages
            //cout << "       hmsLength: " << hmsLength << endl;
            //cout << "       previous Del: " << prevDelimiter << endl;

            if(foundHour == false)
            {
                totalSeconds = totalSeconds + (60 * atoi(time.substr(prevDelimiter,hmsLength).c_str()));

                foundHour = true;
            }
            else if(foundHour == true && foundMin == false)
            {
                totalSeconds = totalSeconds + (60 * atoi(time.substr(prevDelimiter,hmsLength).c_str()));

                foundMin = true;
            }
            else if(foundHour == true && foundMin == true && foundSec == false)
            {
                totalSeconds = totalSeconds + atoi(time.substr(prevDelimiter,hmsLength).c_str());
            }

            ++index;

            prevDelimiter = currDelimiter + 1;
        }
        ++index;
    }

    cout << "       Total Seconds: " << totalSeconds << endl;

    return totalSeconds;
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

            unsigned int initTotalSeconds = 0;
            unsigned int finalTotalSeconds = 0;

            cout << "Input from file: " << input << endl;

            ParseInput(input,initTime,finalTime);

            initTotalSeconds = ConvertToSeconds(initTime);
            finalTotalSeconds = ConvertToSeconds(finalTime);

            cout << "    " << initTime;
            cout << "    " << finalTime << endl;
        }
    }
    else
    {
        cout << "Input File error" << endl;
    }

    return 0;
}
