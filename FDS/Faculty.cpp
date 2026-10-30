#include <iostream>
#include "Faculty.h"

using namespace std;

void Faculty::Display() const
{
    cout << "\n====================================\n";

    cout << "Faculty ID   : "
         << id << endl;

    cout << "Name         : "
         << name << endl;

    cout << "Designation  : "
         << designation << endl;

    cout << "Department   : "
         << department << endl;

    cout << "Building     : "
         << building << endl;

    cout << "Floor        : "
         << floor << endl;

    cout << "Room         : "
         << room << endl;

    cout << "Subject      : "
         << subject << endl;

    cout << "Email        : "
         << email << endl;

    cout << "====================================\n";
}