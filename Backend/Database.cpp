#include "Database.h"

Database::Database()
{
    conn = NULL;
}

Database::~Database()
{
    Disconnect();
}

bool Database::Connect(string password)
{
    conn = mysql_init(NULL);

    if(conn == NULL)
    {
        return false;
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
        mysql_close(conn);
        conn = NULL;

        return false;
    }

    return true;
}

void Database::Disconnect()
{
    if(conn != NULL)
    {
        mysql_close(conn);
        conn = NULL;
    }
}

MYSQL* Database::GetConnection()
{
    return conn;
}