#ifndef FACULTY_H
#define FACULTY_H

#include <string>

using namespace std;

class Faculty
{
public:

    string id;
    string name;
    string designation;
    string department;
    string building;
    int floor;
    string room;
    string subject;
    string email;

    void Display() const;
};

#endif