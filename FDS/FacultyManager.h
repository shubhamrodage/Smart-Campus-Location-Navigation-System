#ifndef FACULTYMANAGER_H
#define FACULTYMANAGER_H

#include <vector>
#include "Faculty.h"

using namespace std;

class FacultyManager
{
private:

    vector<Faculty> facultyList;

public:

    void AddFaculty(
        const Faculty &objFaculty
    );

    void DisplayAll() const;

    vector<Faculty> GetAllFaculty() const;

    int GetCount() const;
};

#endif