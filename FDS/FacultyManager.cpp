#include <iostream>
#include "FacultyManager.h"

using namespace std;


void FacultyManager::AddFaculty(
    const Faculty &objFaculty
)
{
    facultyList.push_back(
        objFaculty
    );
}


void FacultyManager::DisplayAll() const
{
    for(
        int i = 0;
        i < facultyList.size();
        i++
    )
    {
        facultyList[i].Display();
    }
}


vector<Faculty>
FacultyManager::GetAllFaculty() const
{
    return facultyList;
}


int FacultyManager::GetCount() const
{
    return facultyList.size();
}