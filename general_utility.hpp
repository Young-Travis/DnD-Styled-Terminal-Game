#ifndef GENERAL_UTILITY_HPP
#define GENERAL_UTILITY_HPP
#include <cstdlib>
#include <thread>
#include <chrono>
#include <limits>

using namespace std;

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

void waitForEnter()
{
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}


#endif