#include <iostream>
#include <string>
#include <mysql.h>

using namespace std;

int main()
{
    MYSQL *conn;
    string password;

    cout << "Enter MySQL root password: ";
    cin >> password;

    conn = mysql_init(NULL);

    if(conn == NULL)
    {
        cout << "MySQL initialization failed!" << endl;
        return 1;
    }

    if(mysql_real_connect(
        conn,
        "localhost",
        "root",
        password.c_str(),
        "smart_campus",
        3306,
        "/tmp/mysql.sock",
        0
    ) == NULL)
    {
        cout << endl;
        cout << "MySQL Connection Failed!" << endl;
        cout << mysql_error(conn) << endl;

        mysql_close(conn);
        return 1;
    }

    cout << endl;
    cout << "====================================" << endl;
    cout << "   MySQL Connection Successful!" << endl;
    cout << "   Database: smart_campus" << endl;
    cout << "====================================" << endl;

    mysql_close(conn);

    return 0;
}