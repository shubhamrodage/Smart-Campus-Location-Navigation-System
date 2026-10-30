#include <iostream>
#include "DepartmentManager.h"

using namespace std;


void DepartmentManager::AddDepartment(
    const Department &objDepartment
)
{
    departmentList.push_back(
        objDepartment
    );
}


void DepartmentManager::DisplayAll() const
{
    for(
        int i = 0;
        i < departmentList.size();
        i++
    )
    {
        departmentList[i].Display();
    }
}


vector<Department>
DepartmentManager::GetAllDepartments() const
{
    return departmentList;
}


int DepartmentManager::GetCount() const
{
    return departmentList.size();
}