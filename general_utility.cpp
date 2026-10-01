#include "general_utility.hpp"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <limits>

void clearTerminal(int milliseconds)
{
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int getInt()
{
    int response;

    while (!(cin >> response))
    {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return response;
}

float getFloat()
{
    float response;

    while (!(cin >> response))
    {
        cout << "Invalid input. Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return response;
}

bool getYesNo()
{
    char response;

    while (true)
    {
        cin >> response;

        if (response == 'y' || response == 'Y')
        {
            return true;
        }
        else if (response == 'n' || response == 'N')
        {
            return false;
        }
        else
        {
            cout << "Invalid input. Please enter Y or N: ";
        }
    }
}

void waitForEnter()
{
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
