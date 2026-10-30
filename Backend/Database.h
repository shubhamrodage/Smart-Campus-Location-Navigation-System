#ifndef DATABASE_H
#define DATABASE_H

#include <mysql.h>
#include <string>

using namespace std;

class Database
{
    private:
        MYSQL *conn;

    public:
        Database();
        ~Database();

        bool Connect(string password);
        void Disconnect();

        MYSQL* GetConnection();
};

#endif