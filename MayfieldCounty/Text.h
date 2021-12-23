#pragma once

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;


class Text
{
private:
    
public:
    static void printOut(string printString)
    {
        for (int i = 0; i < printString.length(); i++)
        {
            cout << printString[i];

            sleep_for(2us);
        }

    }

    static void printOut(string printString, int insanity) //overloaded function
    {
        char randchar[11] = { '&', '%', '$', '#', '@', '?', '+' , '!', '<', '>', ':' };

        for (int i = 0; i < printString.length(); i++)
        {
            if (rand() % (((insanity + 1) / 5) + 1) == 0 && insanity <= 50 && printString[i] != ' ' && printString[i] != '\n' && printString[i] != '\t') 
                { cout << randchar[rand() % 11]; }
            else { cout << printString[i]; }

            sleep_for(2us);
        }

    }
};

