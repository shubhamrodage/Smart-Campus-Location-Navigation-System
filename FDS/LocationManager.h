#ifndef LOCATIONMANAGER_H
#define LOCATIONMANAGER_H

#include <vector>

#include "Location.h"

using namespace std;

class LocationManager
{
private:

    vector<Location> locations;

public:

    void AddLocation(
        const Location &objLocation
    );

    void DisplayAll() const;

    vector<Location> GetAllLocations() const;

    int GetCount() const;
};

#endif