#include <iostream>
#include <vector>

#include "Location.h"
#include "LocationManager.h"
#include "SearchEngine.h"

#include "Faculty.h"
#include "FacultyManager.h"

#include "Department.h"
#include "DepartmentManager.h"

#include "Building.h"
#include "BuildingManager.h"

using namespace std;

int main()
{
    // =====================================
    // CREATE MANAGERS
    // =====================================

    LocationManager objManager;
    SearchEngine objSearchEngine;

    FacultyManager objFacultyManager;
    DepartmentManager objDepartmentManager;

    BuildingManager objBuildingManager;


    // =====================================
    // LOCATION 1
    // =====================================

    Location objLocation1;

    objLocation1.id = "L001";
    objLocation1.name = "Class Room";
    objLocation1.type = "Class Room";
    objLocation1.building = "B";
    objLocation1.floor = 3;
    objLocation1.room = "B-301";

    objLocation1.department =
        "Department of Computer Science and Engineering(IOT, Cyber Security, Block Chain Technology)";

    objLocation1.description =
        "Teaching Classroom";

    objManager.AddLocation(objLocation1);


    // =====================================
    // LOCATION 2
    // =====================================

    Location objLocation2;

    objLocation2.id = "L002";
    objLocation2.name = "IOT LAB";
    objLocation2.type = "Laboratory";
    objLocation2.building = "B";
    objLocation2.floor = 3;
    objLocation2.room = "B-305";

    objLocation2.department =
        "Department of Computer Science and Engineering(IOT, Cyber Security, Block Chain Technology)";

    objLocation2.description =
        "Internet Of Things LAB";

    objManager.AddLocation(objLocation2);


    // =====================================
    // LOCATION 3
    // =====================================

    Location objLocation3;

    objLocation3.id = "L003";
    objLocation3.name = "DBMS LAB";
    objLocation3.type = "Laboratory";
    objLocation3.building = "B";
    objLocation3.floor = 3;
    objLocation3.room = "B-305";

    objLocation3.department =
        "Department of Computer Science and Engineering(IOT, Cyber Security, Block Chain Technology)";

    objLocation3.description =
        "DBMS LAB";

    objManager.AddLocation(objLocation3);


    // =====================================
    // LOCATION 4
    // =====================================

    Location objLocation4;

    objLocation4.id = "L004";
    objLocation4.name = "Web Technology Lab";
    objLocation4.type = "Laboratory";
    objLocation4.building = "B";
    objLocation4.floor = 3;
    objLocation4.room = "B-306";

    objLocation4.department =
        "Department of Computer Science and Engineering(IOT, Cyber Security, Block Chain Technology)";

    objLocation4.description =
        "Web Technology Lab";

    objManager.AddLocation(objLocation4);


    // =====================================
    // LOCATION 5
    // =====================================

    Location objLocation5;

    objLocation5.id = "L005";
    objLocation5.name = "Cisco networking Lab";
    objLocation5.type = "Laboratory";
    objLocation5.building = "B";
    objLocation5.floor = 3;
    objLocation5.room = "B-307";

    objLocation5.department =
        "Department of Computer Science and Engineering(IOT, Cyber Security, Block Chain Technology)";

    objLocation5.description =
        "Cisco Networking Lab";

    objManager.AddLocation(objLocation5);


    // =====================================
    // LOCATION 6
    // =====================================

    Location objLocation6;

    objLocation6.id = "L006";
    objLocation6.name = "Class Room";
    objLocation6.type = "Class Room";
    objLocation6.building = "B";
    objLocation6.floor = 3;
    objLocation6.room = "B-308";

    objLocation6.department =
        "Department of Computer Science and Engineering(IOT, Cyber Security, Block Chain Technology)";

    objLocation6.description =
        "Teaching Classroom";

    objManager.AddLocation(objLocation6);


    // =====================================
    // LOCATION 7
    // =====================================

    Location objLocation7;

    objLocation7.id = "L007";
    objLocation7.name = "Gent's Toilet";
    objLocation7.type = "Gent's Toilet";
    objLocation7.building = "B";
    objLocation7.floor = 3;
    objLocation7.room = "B-312";

    objLocation7.department =
        "Department of Computer Science and Engineering(IOT, Cyber Security, Block Chain Technology)";

    objLocation7.description =
        "Gent's Toilet";

    objManager.AddLocation(objLocation7);


    // =====================================
    // LOCATION 8
    // =====================================

    Location objLocation8;

    objLocation8.id = "L008";
    objLocation8.name = "Ladies Toilet";
    objLocation8.type = "Ladies Toilet";
    objLocation8.building = "B";
    objLocation8.floor = 3;
    objLocation8.room = "B-313";

    objLocation8.department =
        "Department of Computer Science and Engineering(IOT, Cyber Security, Block Chain Technology)";

    objLocation8.description =
        "Ladies Toilet";

    objManager.AddLocation(objLocation8);


    // =====================================
    // LOCATION 9
    // =====================================

    Location objLocation9;

    objLocation9.id = "L009";
    objLocation9.name = "Tutorial Room";
    objLocation9.type = "Tutorial Room";
    objLocation9.building = "B";
    objLocation9.floor = 3;
    objLocation9.room = "B-314";

    objLocation9.department =
        "Department of Computer Science and Engineering(IOT, Cyber Security, Block Chain Technology)";

    objLocation9.description =
        "Tutorial Room";

    objManager.AddLocation(objLocation9);


    // =====================================
    // FACULTY 1
    // =====================================

    Faculty objFaculty1;

    objFaculty1.id = "F001";
    objFaculty1.name = "Prof. Priya Shelke";

    objFaculty1.department =
        "Department of Computer Science and Engineering(IOT, Cyber Security, Block Chain Technology)";

    objFaculty1.building = "B";
    objFaculty1.floor = 3;
    objFaculty1.cabin = "B-309";
    objFaculty1.email = "priyashelke@college.edu";

    objFacultyManager.AddFaculty(objFaculty1);


    // =====================================
    // FACULTY 2
    // =====================================

    Faculty objFaculty2;

    objFaculty2.id = "F002";
    objFaculty2.name = "Prof. Suruchi Dedgaonkar";

    objFaculty2.department =
        "Department of Computer Science and Engineering(IOT, Cyber Security, Block Chain Technology)";

    objFaculty2.building = "B";
    objFaculty2.floor = 3;
    objFaculty2.cabin = "B-305";
    objFaculty2.email = "suruchidedgaonkar@college.edu";

    objFacultyManager.AddFaculty(objFaculty2);


    // =====================================
    // DEPARTMENT
    // =====================================

    Department objDepartment1;

    objDepartment1.id = "D001";

    objDepartment1.name =
        "Department of Computer Science and Engineering(IOT, Cyber Security, Block Chain Technology)";

    objDepartment1.shortName = "CS-CBI";

    objDepartment1.building = "B";

    objDepartment1.floor = 3;

    objDepartment1.officeRoom = "B-309";

    objDepartment1.description =
        "Department of Computer Science and Engineering(IOT, Cyber Security, Block Chain Technology)";

    objDepartmentManager.AddDepartment(
        objDepartment1
    );


    // =====================================
    // BUILDING
    // =====================================

    Building objBuilding1;

    objBuilding1.id = "B001";

    objBuilding1.name =
        "Computer Science and Engineering";

    objBuilding1.code = "B";

    objBuilding1.totalFloors = 3;

    objBuilding1.description =
        "CSE(Software Engineering), CSE(IOT,Cyber Security, including Block chain Technology)";

    objBuildingManager.AddBuilding(
        objBuilding1
    );


    // =====================================
    // GET ALL LOCATIONS
    // =====================================

    vector<Location> allLocations =
        objManager.GetAllLocations();


    // =====================================
    // MAIN MENU
    // =====================================

    int choice;

    while(true)
    {
        cout << "\n\n====================================\n";
        cout << "       SMART CAMPUS NAVIGATOR\n";
        cout << "====================================\n";

        cout << "\n1. Search Location";
        cout << "\n2. Search Faculty";
        cout << "\n3. Search Department";
        cout << "\n4. Explore Building";
        cout << "\n5. Advanced Search";
        cout << "\n6. Exit";

        cout << "\n\nEnter your choice : ";

        cin >> choice;

        cin.ignore();


        // =====================================
        // 1. SEARCH LOCATION
        // =====================================

        if(choice == 1)
        {
            string searchName;

            cout << "\n====================================\n";
            cout << "       LOCATION SEARCH\n";
            cout << "====================================\n";

            cout << "\nEnter Location Name : ";

            getline(
                cin,
                searchName
            );

            vector<Location> results =
                objSearchEngine.SearchByName(
                    allLocations,
                    searchName
                );

            objSearchEngine.DisplaySearchResults(
                results
            );
        }


        // =====================================
        // 2. SEARCH FACULTY
        // =====================================

        else if(choice == 2)
        {
            string searchFacultyName;

            cout << "\n====================================\n";
            cout << "          FACULTY SEARCH\n";
            cout << "====================================\n";

            cout << "\nEnter Faculty Name : ";

            getline(
                cin,
                searchFacultyName
            );

            Faculty *objFaculty =
                objFacultyManager.SearchFaculty(
                    searchFacultyName
                );

            if(objFaculty != nullptr)
            {
                objFaculty->Display();
            }
            else
            {
                cout << "\nFaculty not found.\n";
            }
        }


        // =====================================
        // 3. SEARCH DEPARTMENT
        // =====================================

        else if(choice == 3)
        {
            string searchDepartmentName;

            cout << "\n====================================\n";
            cout << "        DEPARTMENT SEARCH\n";
            cout << "====================================\n";

            cout << "\nEnter Department Short Name : ";

            getline(
                cin,
                searchDepartmentName
            );

            Department *objDepartment =
                objDepartmentManager.SearchDepartment(
                    searchDepartmentName
                );

            if(objDepartment != nullptr)
            {
                objDepartment->Display();
            }
            else
            {
                cout << "\nDepartment not found.\n";
            }
        }


        // =====================================
        // 4. BUILDING EXPLORER
        // =====================================

        else if(choice == 4)
        {
            string buildingCode;

            cout << "\n====================================\n";
            cout << "        BUILDING EXPLORER\n";
            cout << "====================================\n";

            cout << "\nEnter Building Code : ";

            cin >> buildingCode;

            cin.ignore();


            Building *objBuilding =
                objBuildingManager.SearchBuilding(
                    buildingCode
                );


            if(objBuilding != nullptr)
            {
                objBuilding->Display();

                cout << "\n===== LOCATIONS IN BUILDING "
                     << buildingCode
                     << " =====\n";

                bool bFound = false;

                for(int i = 0;
                    i < allLocations.size();
                    i++)
                {
                    if(allLocations[i].building ==
                       buildingCode)
                    {
                        cout << "\nID          : "
                             << allLocations[i].id;

                        cout << "\nName        : "
                             << allLocations[i].name;

                        cout << "\nType        : "
                             << allLocations[i].type;

                        cout << "\nFloor       : "
                             << allLocations[i].floor;

                        cout << "\nRoom        : "
                             << allLocations[i].room;

                        cout << "\nDescription : "
                             << allLocations[i].description;

                        cout << "\n------------------------------------\n";

                        bFound = true;
                    }
                }

                if(bFound == false)
                {
                    cout << "\nNo locations found in this building.\n";
                }
            }
            else
            {
                cout << "\nBuilding not found.\n";
            }
        }


        // =====================================
        // 5. ADVANCED SEARCH
        // =====================================

        else if(choice == 5)
        {
            int searchChoice;

            cout << "\n====================================\n";
            cout << "          ADVANCED SEARCH\n";
            cout << "====================================\n";

            cout << "\n1. Search by Location Name";
            cout << "\n2. Search by Location Type";
            cout << "\n3. Search by Building";
            cout << "\n4. Search by Type + Building";
            cout << "\n5. Search by Room";
            cout << "\n6. Show All Locations";
            cout << "\n7. Back";

            cout << "\n\nEnter Choice : ";

            cin >> searchChoice;

            cin.ignore();


            // =====================================
            // SEARCH BY NAME
            // =====================================

            if(searchChoice == 1)
            {
                string searchName;

                cout << "\nEnter Location Name : ";

                getline(
                    cin,
                    searchName
                );

                vector<Location> results =
                    objSearchEngine.SearchByName(
                        allLocations,
                        searchName
                    );

                objSearchEngine.DisplaySearchResults(
                    results
                );
            }


            // =====================================
            // SEARCH BY TYPE
            // =====================================

            else if(searchChoice == 2)
            {
                string searchType;

                cout << "\nEnter Location Type : ";

                getline(
                    cin,
                    searchType
                );

                vector<Location> results =
                    objSearchEngine.SearchByType(
                        allLocations,
                        searchType
                    );

                objSearchEngine.DisplaySearchResults(
                    results
                );
            }


            // =====================================
            // SEARCH BY BUILDING
            // =====================================

            else if(searchChoice == 3)
            {
                string buildingCode;

                cout << "\nEnter Building Code : ";

                getline(
                    cin,
                    buildingCode
                );

                vector<Location> results =
                    objSearchEngine.SearchByBuilding(
                        allLocations,
                        buildingCode
                    );

                objSearchEngine.DisplaySearchResults(
                    results
                );
            }


            // =====================================
            // SEARCH BY TYPE + BUILDING
            // =====================================

            else if(searchChoice == 4)
            {
                string searchType;
                string buildingCode;

                cout << "\nEnter Location Type : ";

                getline(
                    cin,
                    searchType
                );

                cout << "Enter Building Code : ";

                getline(
                    cin,
                    buildingCode
                );

                vector<Location> results =
                    objSearchEngine.SearchByTypeAndBuilding(
                        allLocations,
                        searchType,
                        buildingCode
                    );

                objSearchEngine.DisplaySearchResults(
                    results
                );
            }


            // =====================================
            // SEARCH BY ROOM
            // =====================================

            else if(searchChoice == 5)
            {
                string room;

                cout << "\nEnter Room Number : ";

                getline(
                    cin,
                    room
                );

                vector<Location> results =
                    objSearchEngine.SearchByRoom(
                        allLocations,
                        room
                    );

                objSearchEngine.DisplaySearchResults(
                    results
                );
            }


            // =====================================
            // SHOW ALL LOCATIONS
            // =====================================

            else if(searchChoice == 6)
            {
                objSearchEngine.DisplaySearchResults(
                    allLocations
                );
            }


            // =====================================
            // BACK
            // =====================================

            else if(searchChoice == 7)
            {
                cout << "\nReturning to Main Menu...\n";
            }


            // =====================================
            // INVALID
            // =====================================

            else
            {
                cout << "\nInvalid search choice!";
                cout << "\nPlease enter 1 to 7.\n";
            }
        }


        // =====================================
        // 6. EXIT
        // =====================================

        else if(choice == 6)
        {
            cout << "\nThank you for using";
            cout << "\nSmart Campus Navigator!\n";

            break;
        }


        // =====================================
        // INVALID MAIN MENU
        // =====================================

        else
        {
            cout << "\nInvalid choice!";
            cout << "\nPlease enter 1, 2, 3, 4, 5 or 6.\n";
        }
    }


    return 0;
}