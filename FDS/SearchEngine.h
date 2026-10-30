#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include <vector>
#include <string>

#include "Location.h"

using namespace std;

class SearchEngine
{
public:

    vector<Location> SearchByName(
        const vector<Location> &locations,
        string name
    );

    vector<Location> SearchByType(
        const vector<Location> &locations,
        string type
    );

    vector<Location> SearchByBuilding(
        const vector<Location> &locations,
        string building
    );

    vector<Location> SearchByTypeAndBuilding(
        const vector<Location> &locations,
        string type,
        string building
    );

    vector<Location> SearchByRoom(
        const vector<Location> &locations,
        string room
    );

    void DisplaySearchResults(
        const vector<Location> &results
    );
};

#endif