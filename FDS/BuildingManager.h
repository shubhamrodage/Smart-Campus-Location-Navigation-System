#ifndef BUILDINGMANAGER_H
#define BUILDINGMANAGER_H

#include <vector>
#include "Building.h"

using namespace std;

class BuildingManager
{
private:

    vector<Building> buildingList;

public:

    void AddBuilding(
        const Building &objBuilding
    );

    void DisplayAll() const;

    vector<Building> GetAllBuildings() const;

    int GetCount() const;
};

#endif