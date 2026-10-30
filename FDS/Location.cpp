#include <iostream>

#include "Location.h"

using namespace std;

void Location::Display() const
{
    cout << "\n====================================\n";

    cout << "Location ID : " << id << endl;
    cout << "Name        : " << name << endl;
    cout << "Type        : " << type << endl;
    cout << "Building    : " << building << endl;
    cout << "Floor       : " << floor << endl;
    cout << "Room        : " << room << endl;
    cout << "Department  : " << department << endl;
    cout << "Description : " << description << endl;

    cout << "====================================\n";
}