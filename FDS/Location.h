#ifndef LOCATION_H
#define LOCATION_H

#include <string>

using namespace std;

class Location
{
public:

    string id;
    string name;
    string type;

    string building;
    int floor;
    string room;

    string department;
    string description;

    void Display() const;
};

#endif