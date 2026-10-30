#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <string>

using namespace std;

class Department
{
public:

    string id;
    string name;
    string shortName;
    string building;
    int floor;
    string hod;
    string description;

    void Display() const;
};

#endif