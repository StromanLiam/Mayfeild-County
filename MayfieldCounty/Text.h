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
public:
    static void printOut(string printString)
    {
        for (int i = 0; i < printString.length(); i++)
        {
            cout << printString[i];

            sleep_for(2us);
            //sleep_until(system_clock::now() + 3us);
        }

    }
};

