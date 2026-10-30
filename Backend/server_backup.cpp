#include "crow.h"

#include "../FDS/Location.h"
#include "../FDS/LocationManager.h"

#include "../FDS/Faculty.h"
#include "../FDS/FacultyManager.h"

#include "../FDS/Department.h"
#include "../FDS/DepartmentManager.h"

#include "../FDS/Building.h"
#include "../FDS/BuildingManager.h"

using namespace std;

int main()
{
    crow::SimpleApp app;

    // ==========================================
    // MANAGERS
    // ==========================================

    LocationManager objLocationManager;

    FacultyManager objFacultyManager;

    DepartmentManager objDepartmentManager;

    BuildingManager objBuildingManager;

    Location objLocation;


    // =====================================================
    // LOCATION 1
    // =====================================================

    objLocation.id = "L001";
    objLocation.name = "Class Room";
    objLocation.type = "Classroom";
    objLocation.building = "B";
    objLocation.floor = 3;
    objLocation.room = "B-999";
    objLocation.department =
        "Computer Science and Engineering";
    objLocation.description =
        "Computer Science classroom";

    objLocationManager.AddLocation(objLocation);


    // =====================================================
    // LOCATION 2
    // =====================================================

    objLocation.id = "L002";
    objLocation.name = "IOT LAB";
    objLocation.type = "Laboratory";
    objLocation.building = "B";
    objLocation.floor = 3;
    objLocation.room = "B-305";
    objLocation.department =
        "Computer Science and Engineering";
    objLocation.description =
        "Internet of Things Laboratory";

    objLocationManager.AddLocation(objLocation);


    // =====================================================
    // LOCATION 3
    // =====================================================

    objLocation.id = "L003";
    objLocation.name = "DBMS LAB";
    objLocation.type = "Laboratory";
    objLocation.building = "B";
    objLocation.floor = 3;
    objLocation.room = "B-305";
    objLocation.department =
        "Computer Science and Engineering";
    objLocation.description =
        "Database Management System Laboratory";

    objLocationManager.AddLocation(objLocation);


    // =====================================================
    // LOCATION 4
    // =====================================================

    objLocation.id = "L004";
    objLocation.name = "Web Technology Lab";
    objLocation.type = "Laboratory";
    objLocation.building = "B";
    objLocation.floor = 3;
    objLocation.room = "B-306";
    objLocation.department =
        "Computer Science and Engineering";
    objLocation.description =
        "Web Technology Laboratory";

    objLocationManager.AddLocation(objLocation);


    // =====================================================
    // LOCATION 5
    // =====================================================

    objLocation.id = "L005";
    objLocation.name = "Cisco Networking Lab";
    objLocation.type = "Laboratory";
    objLocation.building = "B";
    objLocation.floor = 3;
    objLocation.room = "B-307";
    objLocation.department =
        "Computer Science and Engineering";
    objLocation.description =
        "Cisco Networking Laboratory";

    objLocationManager.AddLocation(objLocation);


    // =====================================================
    // LOCATION 6
    // =====================================================

    objLocation.id = "L006";
    objLocation.name = "Class Room";
    objLocation.type = "Classroom";
    objLocation.building = "B";
    objLocation.floor = 3;
    objLocation.room = "B-308";
    objLocation.department =
        "Computer Science and Engineering";
    objLocation.description =
        "Computer Science classroom";

    objLocationManager.AddLocation(objLocation);


    // =====================================================
    // LOCATION 7
    // =====================================================

    objLocation.id = "L007";
    objLocation.name = "Gent's Toilet";
    objLocation.type = "Toilet";
    objLocation.building = "B";
    objLocation.floor = 3;
    objLocation.room = "B-312";
    objLocation.department =
        "Common Facility";
    objLocation.description =
        "Gent's toilet facility";

    objLocationManager.AddLocation(objLocation);


    // =====================================================
    // LOCATION 8
    // =====================================================

    objLocation.id = "L008";
    objLocation.name = "Ladies Toilet";
    objLocation.type = "Toilet";
    objLocation.building = "B";
    objLocation.floor = 3;
    objLocation.room = "B-313";
    objLocation.department =
        "Common Facility";
    objLocation.description =
        "Ladies toilet facility";

    objLocationManager.AddLocation(objLocation);


    // =====================================================
    // LOCATION 9
    // =====================================================

    objLocation.id = "L009";
    objLocation.name = "Tutorial Room";
    objLocation.type = "Tutorial Room";
    objLocation.building = "B";
    objLocation.floor = 3;
    objLocation.room = "B-314";
    objLocation.department =
        "Computer Science and Engineering";
    objLocation.description =
        "Tutorial and discussion room";

    objLocationManager.AddLocation(objLocation);



    // =====================================================
    // FACULTY 1
    // =====================================================

    Faculty objFaculty1;

    objFaculty1.id =
        "F001";

    objFaculty1.name =
        "Prof. Priya Shelke";

    objFaculty1.designation =
        "Assistant Professor";

    objFaculty1.department =
        "Computer Science and Engineering";

    objFaculty1.building =
        "B";

    objFaculty1.floor =
        3;

    objFaculty1.room =
        "B-309";

    objFaculty1.subject =
        "Data Structures";

    objFaculty1.email =
        "priya@college.edu";

    objFacultyManager.AddFaculty(
        objFaculty1
    );



    // =====================================================
    // FACULTY 2
    // =====================================================

    Faculty objFaculty2;

    objFaculty2.id =
        "F002";

    objFaculty2.name =
        "Prof. Suruchi Dedgaonkar";

    objFaculty2.designation =
        "Assistant Professor";

    objFaculty2.department =
        "Computer Science and Engineering";

    objFaculty2.building =
        "B";

    objFaculty2.floor =
        3;

    objFaculty2.room =
        "B-305";

    objFaculty2.subject =
        "Internet of Things";

    objFaculty2.email =
        "suruchi@college.edu";

    objFacultyManager.AddFaculty(
        objFaculty2
    );



    // =====================================================
    // DEPARTMENT 1
    // =====================================================

    Department objDepartment1;

    objDepartment1.id =
        "D001";

    objDepartment1.name =
        "Computer Science and Engineering";

    objDepartment1.shortName =
        "CSE";

    objDepartment1.building =
        "B";

    objDepartment1.floor =
        3;

    objDepartment1.hod =
        "Not Assigned";

    objDepartment1.description =
        "Department of Computer Science and Engineering";

    objDepartmentManager.AddDepartment(
        objDepartment1
    );



    // =====================================================
    // BUILDING A
    // =====================================================

    Building objBuilding1;

    objBuilding1.id =
        "B001";

    objBuilding1.name =
        "Building A";

    objBuilding1.code =
        "A";

    objBuilding1.floors =
        0;

    objBuilding1.description =
        "Coming Soon";

    objBuildingManager.AddBuilding(
        objBuilding1
    );


    // =====================================================
    // BUILDING B
    // =====================================================

    Building objBuilding2;

    objBuilding2.id =
        "B002";

    objBuilding2.name =
        "Academic Block";

    objBuilding2.code =
        "B";

    objBuilding2.floors =
        3;

    objBuilding2.description =
        "Academic building containing classrooms, laboratories and faculty rooms.";

    objBuildingManager.AddBuilding(
        objBuilding2
    );


    // =====================================================
    // BUILDING C
    // =====================================================

    Building objBuilding3;

    objBuilding3.id =
        "B003";

    objBuilding3.name =
        "Building C";

    objBuilding3.code =
        "C";

    objBuilding3.floors =
        0;

    objBuilding3.description =
        "Coming Soon";

    objBuildingManager.AddBuilding(
        objBuilding3
    );


    // =====================================================
    // BUILDING D
    // =====================================================

    Building objBuilding4;

    objBuilding4.id =
        "B004";

    objBuilding4.name =
        "Building D";

    objBuilding4.code =
        "D";

    objBuilding4.floors =
        0;

    objBuilding4.description =
        "Coming Soon";

    objBuildingManager.AddBuilding(
        objBuilding4
    );


    // =====================================================
    // BUILDING E
    // =====================================================

    Building objBuilding5;

    objBuilding5.id =
        "B005";

    objBuilding5.name =
        "Building E";

    objBuilding5.code =
        "E";

    objBuilding5.floors =
        0;

    objBuilding5.description =
        "Coming Soon";

    objBuildingManager.AddBuilding(
        objBuilding5
    );



    // ==========================================
    // TEST API
    // ==========================================

    CROW_ROUTE(app, "/api/test")
    ([]()
    {
        crow::response response;

        response.code = 200;

        response.set_header(
            "Access-Control-Allow-Origin",
            "*"
        );

        response.set_header(
            "Access-Control-Allow-Methods",
            "GET, POST, OPTIONS"
        );

        response.set_header(
            "Access-Control-Allow-Headers",
            "Content-Type"
        );

        response.set_header(
            "Content-Type",
            "application/json"
        );

        response.body =
            R"({"status":"success","message":"Smart Campus Backend is Running"})";

        return response;
    });



    // ==========================================
    // LOCATIONS API
    // ==========================================

    CROW_ROUTE(app, "/api/locations")
    ([&objLocationManager]()
    {
        vector<Location> locations =
            objLocationManager.GetAllLocations();

        crow::json::wvalue result;

        result["count"] =
            locations.size();

        for(
            int i = 0;
            i < locations.size();
            i++
        )
        {
            result["locations"][i]["id"] =
                locations[i].id;

            result["locations"][i]["name"] =
                locations[i].name;

            result["locations"][i]["type"] =
                locations[i].type;

            result["locations"][i]["building"] =
                locations[i].building;

            result["locations"][i]["floor"] =
                locations[i].floor;

            result["locations"][i]["room"] =
                locations[i].room;

            result["locations"][i]["department"] =
                locations[i].department;

            result["locations"][i]["description"] =
                locations[i].description;
        }

        crow::response response(result);

        response.set_header(
            "Access-Control-Allow-Origin",
            "*"
        );

        response.set_header(
            "Access-Control-Allow-Methods",
            "GET, POST, OPTIONS"
        );

        response.set_header(
            "Access-Control-Allow-Headers",
            "Content-Type"
        );

        response.set_header(
            "Content-Type",
            "application/json"
        );

        return response;
    });



    // ==========================================
    // FACULTY API
    // ==========================================

    CROW_ROUTE(app, "/api/faculty")
    ([&objFacultyManager]()
    {
        vector<Faculty> faculty =
            objFacultyManager.GetAllFaculty();

        crow::json::wvalue result;

        result["count"] =
            faculty.size();

        for(
            int i = 0;
            i < faculty.size();
            i++
        )
        {
            result["faculty"][i]["id"] =
                faculty[i].id;

            result["faculty"][i]["name"] =
                faculty[i].name;

            result["faculty"][i]["designation"] =
                faculty[i].designation;

            result["faculty"][i]["department"] =
                faculty[i].department;

            result["faculty"][i]["building"] =
                faculty[i].building;

            result["faculty"][i]["floor"] =
                faculty[i].floor;

            result["faculty"][i]["room"] =
                faculty[i].room;

            result["faculty"][i]["subject"] =
                faculty[i].subject;

            result["faculty"][i]["email"] =
                faculty[i].email;
        }

        crow::response response(result);

        response.set_header(
            "Access-Control-Allow-Origin",
            "*"
        );

        response.set_header(
            "Access-Control-Allow-Methods",
            "GET, POST, OPTIONS"
        );

        response.set_header(
            "Access-Control-Allow-Headers",
            "Content-Type"
        );

        response.set_header(
            "Content-Type",
            "application/json"
        );

        return response;
    });



    // ==========================================
    // DEPARTMENT API
    // ==========================================

    CROW_ROUTE(app, "/api/departments")
    ([&objDepartmentManager]()
    {
        vector<Department> departments =
            objDepartmentManager.GetAllDepartments();

        crow::json::wvalue result;

        result["count"] =
            departments.size();

        for(
            int i = 0;
            i < departments.size();
            i++
        )
        {
            result["departments"][i]["id"] =
                departments[i].id;

            result["departments"][i]["name"] =
                departments[i].name;

            result["departments"][i]["shortName"] =
                departments[i].shortName;

            result["departments"][i]["building"] =
                departments[i].building;

            result["departments"][i]["floor"] =
                departments[i].floor;

            result["departments"][i]["hod"] =
                departments[i].hod;

            result["departments"][i]["description"] =
                departments[i].description;
        }

        crow::response response(result);

        response.set_header(
            "Access-Control-Allow-Origin",
            "*"
        );

        response.set_header(
            "Access-Control-Allow-Methods",
            "GET, POST, OPTIONS"
        );

        response.set_header(
            "Access-Control-Allow-Headers",
            "Content-Type"
        );

        response.set_header(
            "Content-Type",
            "application/json"
        );

        return response;
    });



    // ==========================================
    // BUILDINGS API
    // ==========================================

    CROW_ROUTE(app, "/api/buildings")
    ([&objBuildingManager]()
    {
        vector<Building> buildings =
            objBuildingManager.GetAllBuildings();

        crow::json::wvalue result;

        result["count"] =
            buildings.size();

        for(
            int i = 0;
            i < buildings.size();
            i++
        )
        {
            result["buildings"][i]["id"] =
                buildings[i].id;

            result["buildings"][i]["name"] =
                buildings[i].name;

            result["buildings"][i]["code"] =
                buildings[i].code;

            result["buildings"][i]["floors"] =
                buildings[i].floors;

            result["buildings"][i]["description"] =
                buildings[i].description;
        }

        crow::response response(result);

        response.set_header(
            "Access-Control-Allow-Origin",
            "*"
        );

        response.set_header(
            "Access-Control-Allow-Methods",
            "GET, POST, OPTIONS"
        );

        response.set_header(
            "Access-Control-Allow-Headers",
            "Content-Type"
        );

        response.set_header(
            "Content-Type",
            "application/json"
        );

        return response;
    });



    // ==========================================
    // BUILDING DETAILS API
    // ==========================================

    CROW_ROUTE(app, "/api/buildings/<string>")
    ([&objBuildingManager](string id)
    {
        vector<Building> buildings =
            objBuildingManager.GetAllBuildings();

        for(
            int i = 0;
            i < buildings.size();
            i++
        )
        {
            if(
                buildings[i].id == id
            )
            {
                crow::json::wvalue result;

                result["id"] =
                    buildings[i].id;

                result["name"] =
                    buildings[i].name;

                result["code"] =
                    buildings[i].code;

                result["floors"] =
                    buildings[i].floors;

                result["description"] =
                    buildings[i].description;


                crow::response response(
                    result
                );

                response.set_header(
                    "Access-Control-Allow-Origin",
                    "*"
                );

                response.set_header(
                    "Access-Control-Allow-Methods",
                    "GET, POST, OPTIONS"
                );

                response.set_header(
                    "Access-Control-Allow-Headers",
                    "Content-Type"
                );

                response.set_header(
                    "Content-Type",
                    "application/json"
                );

                return response;
            }
        }


        // ==========================================
        // BUILDING NOT FOUND
        // ==========================================

        crow::json::wvalue error;

        error["status"] =
            "error";

        error["message"] =
            "Building not found";


        crow::response response(
            404,
            error
        );

        response.set_header(
            "Access-Control-Allow-Origin",
            "*"
        );

        response.set_header(
            "Content-Type",
            "application/json"
        );

        return response;
    });



    // ==========================================
    // START SERVER
    // ==========================================

    app.port(8080)
       .multithreaded()
       .run();


    return 0;
}