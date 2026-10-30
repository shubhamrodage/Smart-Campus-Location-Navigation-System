#include "crow.h"
#include "Database.h"

#include "../FDS/Location.h"
#include "../FDS/LocationManager.h"
#include "../FDS/LocationSorting.h"
#include "../FDS/RequestQueue.h"
#include "../FDS/NavigationStack.h"

#include "../FDS/Faculty.h"
#include "../FDS/FacultyManager.h"

#include "../FDS/Department.h"
#include "../FDS/DepartmentManager.h"

#include "../FDS/Building.h"
#include "../FDS/BuildingManager.h"

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main()
{
    crow::SimpleApp app;

    // ==========================================
    // MYSQL DATABASE CONNECTION
    // ==========================================

    Database objDatabase;

    const char* dbPassword = getenv("MYSQL_PASSWORD");

    if(dbPassword == NULL)
    {
        cout << "MYSQL_PASSWORD environment variable is not set!" << endl;
        return 1;
    }

    if(!objDatabase.Connect(dbPassword))
    {
        cout << "MySQL Connection Failed!" << endl;
        return 1;
    }

    cout << "====================================" << endl;
    cout << "   MySQL Connection Successful!" << endl;
    cout << "   Database: smart_campus" << endl;
    cout << "====================================" << endl;


    // ==========================================
    // MANAGERS
    // ==========================================

    LocationManager objLocationManager;
    FacultyManager objFacultyManager;
    DepartmentManager objDepartmentManager;
    BuildingManager objBuildingManager;
    Location objLocation;

    LocationSorting objLocationSorting;

    // FDS Queue
    RequestQueue objRequestQueue;

    // FDS Stack
    NavigationStack objNavigationStack;


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
    // MYSQL + QUEUE + BUBBLE SORT
    // ==========================================

    CROW_ROUTE(app, "/api/locations")
    ([&objDatabase, &objLocationSorting, &objRequestQueue]()
    {
        // ==========================================
        // FDS QUEUE
        // ==========================================

        objRequestQueue.Enqueue(
            "Location Search Request"
        );

        string strRequest =
            objRequestQueue.Dequeue();

        cout << endl;
        cout << "====================================" << endl;
        cout << "   QUEUE REQUEST PROCESSING" << endl;
        cout << "====================================" << endl;
        cout << "Processing : "
             << strRequest << endl;
        cout << "Queue Type : FIFO" << endl;
        cout << "====================================" << endl;


        MYSQL* conn =
            objDatabase.GetConnection();

        crow::json::wvalue result;

        if(conn == NULL)
        {
            result["status"] =
                "error";

            result["message"] =
                "Database connection not available";

            crow::response response(
                500,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }


        // ==========================================
        // MYSQL QUERY
        // ==========================================

        string query =
            "SELECT location_id, location_name, location_type, "
            "building_code, floor, room_number, department, description "
            "FROM locations";

        if(mysql_query(
            conn,
            query.c_str()
        ) != 0)
        {
            result["status"] =
                "error";

            result["message"] =
                mysql_error(conn);

            crow::response response(
                500,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }


        MYSQL_RES* res =
            mysql_store_result(conn);

        if(res == NULL)
        {
            result["status"] =
                "error";

            result["message"] =
                mysql_error(conn);

            crow::response response(
                500,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }


        // ==========================================
        // LOCATION RECORD STRUCTURE
        // ==========================================

        struct LocationRecord
        {
            string id;
            string name;
            string type;
            string building;
            string floor;
            string room;
            string department;
            string description;
        };


        // ==========================================
        // STORE MYSQL DATA
        // ==========================================

        LocationRecord Arr[100];

        string RoomArr[100];

        bool bUsed[100];

        int iCount = 0;

        MYSQL_ROW row;


        while(
            (row = mysql_fetch_row(res))
            != NULL
        )
        {
            if(iCount >= 100)
            {
                break;
            }

            Arr[iCount].id =
                row[0] != NULL
                ? row[0]
                : "";

            Arr[iCount].name =
                row[1] != NULL
                ? row[1]
                : "";

            Arr[iCount].type =
                row[2] != NULL
                ? row[2]
                : "";

            Arr[iCount].building =
                row[3] != NULL
                ? row[3]
                : "";

            Arr[iCount].floor =
                row[4] != NULL
                ? row[4]
                : "";

            Arr[iCount].room =
                row[5] != NULL
                ? row[5]
                : "";

            Arr[iCount].department =
                row[6] != NULL
                ? row[6]
                : "";

            Arr[iCount].description =
                row[7] != NULL
                ? row[7]
                : "";

            RoomArr[iCount] =
                Arr[iCount].room;

            bUsed[iCount] =
                false;

            iCount++;
        }


        mysql_free_result(res);


        // ==========================================
        // FDS BUBBLE SORT
        // ==========================================

        objLocationSorting.BubbleSort(
            RoomArr,
            iCount
        );


        // ==========================================
        // CREATE SORTED JSON RESULT
        // ==========================================

        int iSorted = 0;

        for(
            int i = 0;
            i < iCount;
            i++
        )
        {
            for(
                int j = 0;
                j < iCount;
                j++
            )
            {
                if(
                    !bUsed[j] &&
                    Arr[j].room == RoomArr[i]
                )
                {
                    result["locations"][iSorted]["id"] =
                        Arr[j].id;

                    result["locations"][iSorted]["name"] =
                        Arr[j].name;

                    result["locations"][iSorted]["type"] =
                        Arr[j].type;

                    result["locations"][iSorted]["building"] =
                        Arr[j].building;

                    result["locations"][iSorted]["floor"] =
                        Arr[j].floor;

                    result["locations"][iSorted]["room"] =
                        Arr[j].room;

                    result["locations"][iSorted]["department"] =
                        Arr[j].department;

                    result["locations"][iSorted]["description"] =
                        Arr[j].description;

                    bUsed[j] =
                        true;

                    iSorted++;

                    break;
                }
            }
        }


        // ==========================================
        // TOTAL COUNT
        // ==========================================

        result["count"] =
            iSorted;


        // ==========================================
        // RESPONSE
        // ==========================================

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
    // FDS STACK - NAVIGATION HISTORY
    // ==========================================

    // ==========================================
    // PUSH PAGE INTO STACK
    // ==========================================

    CROW_ROUTE(app, "/api/navigation/push")
    .methods(crow::HTTPMethod::POST)
    ([&objNavigationStack](const crow::request& req)
    {
        auto body =
            crow::json::load(req.body);

        crow::json::wvalue result;

        if(!body)
        {
            result["status"] =
                "error";

            result["message"] =
                "Invalid JSON request";

            crow::response response(
                400,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }

        if(!body.has("page"))
        {
            result["status"] =
                "error";

            result["message"] =
                "Page name is required";

            crow::response response(
                400,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }

        string strPage =
            body["page"].s();

        // ==========================================
        // FDS STACK PUSH
        // ==========================================

        objNavigationStack.Push(
            strPage
        );

        cout << endl;
        cout << "====================================" << endl;
        cout << "       STACK NAVIGATION" << endl;
        cout << "====================================" << endl;
        cout << "Pushed Page : "
             << strPage << endl;
        cout << "Stack Type  : LIFO" << endl;
        cout << "====================================" << endl;


        result["status"] =
            "success";

        result["message"] =
            "Page pushed into navigation stack";

        result["page"] =
            strPage;


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
    // POP PAGE FROM STACK
    // ==========================================

    CROW_ROUTE(app, "/api/navigation/back")
    ([&objNavigationStack]()
    {
        crow::json::wvalue result;

        string strPage =
            objNavigationStack.Pop();

        cout << endl;
        cout << "====================================" << endl;
        cout << "       STACK NAVIGATION" << endl;
        cout << "====================================" << endl;


        // ==========================================
        // CHECK STACK
        // ==========================================

        if(strPage == "")
        {
            cout << "Stack is Empty" << endl;

            result["status"] =
                "empty";

            result["message"] =
                "Navigation history is empty";
        }
        else
        {
            cout << "Popped Page : "
                 << strPage << endl;

            cout << "Stack Type  : LIFO" << endl;

            result["status"] =
                "success";

            result["message"] =
                "Previous page retrieved";

            result["page"] =
                strPage;
        }

        cout << "====================================" << endl;


        crow::response response(result);

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
    // FACULTY API - MYSQL
    // ==========================================

    CROW_ROUTE(app, "/api/faculty")
    ([&objDatabase]()
    {
        MYSQL* conn =
            objDatabase.GetConnection();

        crow::json::wvalue result;

        if(conn == NULL)
        {
            result["status"] =
                "error";

            result["message"] =
                "Database connection not available";

            crow::response response(
                500,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }


        string query =
            "SELECT faculty_id, faculty_name, designation, building_code, "
            "floor, cabin, email, department "
            "FROM faculty";


        if(mysql_query(
            conn,
            query.c_str()
        ) != 0)
        {
            result["status"] =
                "error";

            result["message"] =
                mysql_error(conn);

            crow::response response(
                500,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }


        MYSQL_RES* res =
            mysql_store_result(conn);

        if(res == NULL)
        {
            result["status"] =
                "error";

            result["message"] =
                mysql_error(conn);

            crow::response response(
                500,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }


        MYSQL_ROW row;

        int i = 0;


        while(
            (row = mysql_fetch_row(res))
            != NULL
        )
        {
            result["faculty"][i]["id"] =
                row[0] != NULL
                ? row[0]
                : "";

            result["faculty"][i]["name"] =
                row[1] != NULL
                ? row[1]
                : "";

            result["faculty"][i]["designation"] =
                row[2] != NULL
                ? row[2]
                : "";

            result["faculty"][i]["building"] =
                row[3] != NULL
                ? row[3]
                : "";

            result["faculty"][i]["floor"] =
                row[4] != NULL
                ? row[4]
                : "";

            result["faculty"][i]["room"] =
                row[5] != NULL
                ? row[5]
                : "";

            result["faculty"][i]["email"] =
                row[6] != NULL
                ? row[6]
                : "";

            result["faculty"][i]["department"] =
                row[7] != NULL
                ? row[7]
                : "";

            result["faculty"][i]["subject"] =
                "Not Specified";

            i++;
        }


        mysql_free_result(res);


        result["count"] =
            i;


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
    // DEPARTMENT API - MYSQL
    // ==========================================

    CROW_ROUTE(app, "/api/departments")
    ([&objDatabase]()
    {
        MYSQL* conn =
            objDatabase.GetConnection();

        crow::json::wvalue result;

        if(conn == NULL)
        {
            result["status"] =
                "error";

            result["message"] =
                "Database connection not available";

            crow::response response(
                500,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }


        string query =
            "SELECT department_id, department_name, "
            "building_code, floor, status "
            "FROM departments";


        if(mysql_query(
            conn,
            query.c_str()
        ) != 0)
        {
            result["status"] =
                "error";

            result["message"] =
                mysql_error(conn);

            crow::response response(
                500,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }


        MYSQL_RES* res =
            mysql_store_result(conn);

        if(res == NULL)
        {
            result["status"] =
                "error";

            result["message"] =
                mysql_error(conn);

            crow::response response(
                500,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }


        MYSQL_ROW row;

        int i = 0;


        while(
            (row = mysql_fetch_row(res))
            != NULL
        )
        {
            result["departments"][i]["id"] =
                row[0] != NULL
                ? row[0]
                : "";

            result["departments"][i]["name"] =
                row[1] != NULL
                ? row[1]
                : "";


            if(row[1] != NULL)
            {
                string departmentName =
                    row[1];

                if(
                    departmentName.find(
                        "Computer Engineering"
                    ) != string::npos
                )
                {
                    result["departments"][i]["shortName"] =
                        "CE";
                }
                else if(
                    departmentName.find(
                        "Computer Science"
                    ) != string::npos
                )
                {
                    result["departments"][i]["shortName"] =
                        "CSE";
                }
                else
                {
                    result["departments"][i]["shortName"] =
                        "N/A";
                }
            }
            else
            {
                result["departments"][i]["shortName"] =
                    "N/A";
            }


            result["departments"][i]["building"] =
                row[2] != NULL
                ? row[2]
                : "";

            result["departments"][i]["floor"] =
                row[3] != NULL
                ? row[3]
                : "";

            result["departments"][i]["hod"] =
                "Not Assigned";

            result["departments"][i]["description"] =
                row[1] != NULL
                ? row[1]
                : "";

            i++;
        }


        mysql_free_result(res);


        result["count"] =
            i;


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
    // BUILDINGS API - MYSQL
    // ==========================================

    CROW_ROUTE(app, "/api/buildings")
    ([&objDatabase]()
    {
        MYSQL* conn =
            objDatabase.GetConnection();

        crow::json::wvalue result;

        if(conn == NULL)
        {
            result["status"] =
                "error";

            result["message"] =
                "Database connection not available";

            crow::response response(
                500,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }


        string query =
            "SELECT building_id, building_name, building_code, "
            "floors, description "
            "FROM buildings";


        if(mysql_query(
            conn,
            query.c_str()
        ) != 0)
        {
            result["status"] =
                "error";

            result["message"] =
                mysql_error(conn);

            crow::response response(
                500,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }


        MYSQL_RES* res =
            mysql_store_result(conn);

        if(res == NULL)
        {
            result["status"] =
                "error";

            result["message"] =
                mysql_error(conn);

            crow::response response(
                500,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }


        MYSQL_ROW row;

        int i = 0;


        while(
            (row = mysql_fetch_row(res))
            != NULL
        )
        {
            result["buildings"][i]["id"] =
                row[0] != NULL
                ? row[0]
                : "";

            result["buildings"][i]["name"] =
                row[1] != NULL
                ? row[1]
                : "";

            result["buildings"][i]["code"] =
                row[2] != NULL
                ? row[2]
                : "";

            result["buildings"][i]["floors"] =
                row[3] != NULL
                ? stoi(row[3])
                : 0;

            result["buildings"][i]["description"] =
                row[4] != NULL
                ? row[4]
                : "";

            i++;
        }


        mysql_free_result(res);


        result["count"] =
            i;


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
    // BUILDING DETAILS API - MYSQL
    // ==========================================

    CROW_ROUTE(app, "/api/buildings/<string>")
    ([&objDatabase](string id)
    {
        MYSQL* conn =
            objDatabase.GetConnection();

        crow::json::wvalue result;

        if(conn == NULL)
        {
            result["status"] =
                "error";

            result["message"] =
                "Database connection not available";

            crow::response response(
                500,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }


        // ==========================================
        // ESCAPE ID FOR SAFE SQL QUERY
        // ==========================================

        char escapedId[256];

        mysql_real_escape_string(
            conn,
            escapedId,
            id.c_str(),
            id.length()
        );


        string query =
            "SELECT building_id, building_name, building_code, "
            "floors, description "
            "FROM buildings WHERE building_id = '" +
            string(escapedId) +
            "'";


        if(mysql_query(
            conn,
            query.c_str()
        ) != 0)
        {
            result["status"] =
                "error";

            result["message"] =
                mysql_error(conn);

            crow::response response(
                500,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }


        MYSQL_RES* res =
            mysql_store_result(conn);

        if(res == NULL)
        {
            result["status"] =
                "error";

            result["message"] =
                mysql_error(conn);

            crow::response response(
                500,
                result
            );

            response.set_header(
                "Access-Control-Allow-Origin",
                "*"
            );

            return response;
        }


        MYSQL_ROW row =
            mysql_fetch_row(res);


        if(row != NULL)
        {
            result["id"] =
                row[0] != NULL
                ? row[0]
                : "";

            result["name"] =
                row[1] != NULL
                ? row[1]
                : "";

            result["code"] =
                row[2] != NULL
                ? row[2]
                : "";

            result["floors"] =
                row[3] != NULL
                ? stoi(row[3])
                : 0;

            result["description"] =
                row[4] != NULL
                ? row[4]
                : "";


            mysql_free_result(res);


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
        }


        mysql_free_result(res);


        // ==========================================
        // BUILDING NOT FOUND
        // ==========================================

        result["status"] =
            "error";

        result["message"] =
            "Building not found";


        crow::response response(
            404,
            result
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

    cout << endl;

    cout << "====================================" << endl;
    cout << "   Smart Campus Backend Running" << endl;
    cout << "   http://127.0.0.1:8080" << endl;
    cout << "====================================" << endl;


    app.port(8080)
       .multithreaded()
       .run();


    return 0;
}