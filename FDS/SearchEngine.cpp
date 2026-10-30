#include <iostream>
#include <algorithm>
#include <cctype>

#include "SearchEngine.h"

using namespace std;


// =====================================
// CONVERT STRING TO LOWERCASE
// =====================================

string ConvertToLower(string str)
{
    transform(
        str.begin(),
        str.end(),
        str.begin(),
        [](unsigned char ch)
        {
            return tolower(ch);
        }
    );

    return str;
}


// =====================================
// SEARCH BY NAME
// =====================================

vector<Location>
SearchEngine::SearchByName(
    const vector<Location> &locations,
    string name)
{
    vector<Location> results;

    name = ConvertToLower(name);

    for(int i = 0;
        i < locations.size();
        i++)
    {
        string currentName =
            ConvertToLower(
                locations[i].name
            );

        if(currentName.find(name)
            != string::npos)
        {
            results.push_back(
                locations[i]
            );
        }
    }

    return results;
}


// =====================================
// SEARCH BY TYPE
// =====================================

vector<Location>
SearchEngine::SearchByType(
    const vector<Location> &locations,
    string type)
{
    vector<Location> results;

    type = ConvertToLower(type);

    for(int i = 0;
        i < locations.size();
        i++)
    {
        string currentType =
            ConvertToLower(
                locations[i].type
            );

        if(currentType == type)
        {
            results.push_back(
                locations[i]
            );
        }
    }

    return results;
}


// =====================================
// SEARCH BY BUILDING
// =====================================

vector<Location>
SearchEngine::SearchByBuilding(
    const vector<Location> &locations,
    string building)
{
    vector<Location> results;

    building =
        ConvertToLower(
            building
        );

    for(int i = 0;
        i < locations.size();
        i++)
    {
        string currentBuilding =
            ConvertToLower(
                locations[i].building
            );

        if(currentBuilding == building)
        {
            results.push_back(
                locations[i]
            );
        }
    }

    return results;
}


// =====================================
// SEARCH BY TYPE + BUILDING
// =====================================

vector<Location>
SearchEngine::SearchByTypeAndBuilding(
    const vector<Location> &locations,
    string type,
    string building)
{
    vector<Location> results;

    type =
        ConvertToLower(type);

    building =
        ConvertToLower(building);

    for(int i = 0;
        i < locations.size();
        i++)
    {
        string currentType =
            ConvertToLower(
                locations[i].type
            );

        string currentBuilding =
            ConvertToLower(
                locations[i].building
            );

        if(currentType == type &&
           currentBuilding == building)
        {
            results.push_back(
                locations[i]
            );
        }
    }

    return results;
}


// =====================================
// SEARCH BY ROOM
// =====================================

vector<Location>
SearchEngine::SearchByRoom(
    const vector<Location> &locations,
    string room)
{
    vector<Location> results;

    room =
        ConvertToLower(room);

    for(int i = 0;
        i < locations.size();
        i++)
    {
        string currentRoom =
            ConvertToLower(
                locations[i].room
            );

        if(currentRoom == room)
        {
            results.push_back(
                locations[i]
            );
        }
    }

    return results;
}


// =====================================
// DISPLAY SEARCH RESULTS
// =====================================

void SearchEngine::DisplaySearchResults(
    const vector<Location> &results)
{
    if(results.empty())
    {
        cout << "\nNo matching location found.\n";

        return;
    }

    cout << "\n"
         << results.size()
         << " location(s) found.\n";

    for(int i = 0;
        i < results.size();
        i++)
    {
        cout << "\n";

        cout << "[" << i + 1 << "] "
             << results[i].name
             << endl;

        cout << "    Building : "
             << results[i].building
             << endl;

        cout << "    Floor    : "
             << results[i].floor
             << endl;

        cout << "    Room     : "
             << results[i].room
             << endl;
    }
}