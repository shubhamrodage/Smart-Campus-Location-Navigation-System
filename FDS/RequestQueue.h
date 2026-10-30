#ifndef REQUESTQUEUE_H
#define REQUESTQUEUE_H

#include <iostream>
#include <string>

using namespace std;

class RequestQueue
{
    private:
        string Arr[50];

        int iFront;
        int iRear;

    public:

        RequestQueue()
        {
            iFront = -1;
            iRear = -1;
        }

        void Enqueue(string strRequest)
        {
            if(iRear == 49)
            {
                cout << "Queue is Full" << endl;
                return;
            }

            if(iFront == -1)
            {
                iFront = 0;
            }

            iRear++;

            Arr[iRear] = strRequest;
        }

        string Dequeue()
        {
            if(iFront == -1 || iFront > iRear)
            {
                return "";
            }

            string strRequest = Arr[iFront];

            iFront++;

            return strRequest;
        }

        void Display()
        {
            if(iFront == -1 || iFront > iRear)
            {
                cout << "Queue is Empty" << endl;
                return;
            }

            cout << endl;
            cout << "Search Request Queue:" << endl;

            for(int i = iFront; i <= iRear; i++)
            {
                cout << Arr[i] << endl;
            }
        }

        bool IsEmpty()
        {
            return iFront == -1 || iFront > iRear;
        }
};

#endif