#include <iostream>

#include "LocationManager.h"

using namespace std;


// =====================================
// ADD LOCATION
// =====================================

void LocationManager::AddLocation(
    const Location &objLocation)
{
    locations.push_back(
        objLocation
    );
}


// =====================================
// DISPLAY ALL
// =====================================

void LocationManager::DisplayAll() const
{
    for(int i = 0;
        i < locations.size();
        i++)
    {
        locations[i].Display();
    }
}


// =====================================
// GET ALL LOCATIONS
// =====================================

vector<Location>
LocationManager::GetAllLocations() const
{
    return locations;
}


// =====================================
// GET COUNT
// =====================================

int LocationManager::GetCount() const
{
    return locations.size();
}