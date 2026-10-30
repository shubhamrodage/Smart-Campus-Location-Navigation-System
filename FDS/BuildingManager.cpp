#include <iostream>
#include "BuildingManager.h"

using namespace std;


void BuildingManager::AddBuilding(
    const Building &objBuilding
)
{
    buildingList.push_back(
        objBuilding
    );
}


void BuildingManager::DisplayAll() const
{
    for(
        int i = 0;
        i < buildingList.size();
        i++
    )
    {
        buildingList[i].Display();
    }
}


vector<Building>
BuildingManager::GetAllBuildings() const
{
    return buildingList;
}


int BuildingManager::GetCount() const
{
    return buildingList.size();
}