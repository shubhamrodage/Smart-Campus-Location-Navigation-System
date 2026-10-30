#ifndef DEPARTMENTMANAGER_H
#define DEPARTMENTMANAGER_H

#include <vector>
#include "Department.h"

using namespace std;

class DepartmentManager
{
private:

    vector<Department> departmentList;

public:

    void AddDepartment(
        const Department &objDepartment
    );

    void DisplayAll() const;

    vector<Department> GetAllDepartments() const;

    int GetCount() const;
};

#endif