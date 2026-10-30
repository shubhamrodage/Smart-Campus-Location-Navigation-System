#include <iostream>
#include "Department.h"

using namespace std;

void Department::Display() const
{
    cout << "\n====================================\n";

    cout << "Department ID : "
         << id << endl;

    cout << "Name          : "
         << name << endl;

    cout << "Short Name    : "
         << shortName << endl;

    cout << "Building      : "
         << building << endl;

    cout << "Floor         : "
         << floor << endl;

    cout << "HOD           : "
         << hod << endl;

    cout << "Description   : "
         << description << endl;

    cout << "====================================\n";
}