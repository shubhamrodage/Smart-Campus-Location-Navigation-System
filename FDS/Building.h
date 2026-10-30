#ifndef BUILDING_H
#define BUILDING_H

#include <string>

using namespace std;

class Building
{
public:

    string id;
    string name;
    string code;
    int floors;
    string description;

    void Display() const;
};

#endif