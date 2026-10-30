#include <iostream>
#include "Building.h"

using namespace std;

void Building::Display() const
{
    cout << "\n====================================\n";

    cout << "Building ID   : "
         << id << endl;

    cout << "Name          : "
         << name << endl;

    cout << "Code          : "
         << code << endl;

    cout << "Floors        : "
         << floors << endl;

    cout << "Description   : "
         << description << endl;

    cout << "====================================\n";
}