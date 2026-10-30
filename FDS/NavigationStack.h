#ifndef NAVIGATIONSTACK_H
#define NAVIGATIONSTACK_H

#include <iostream>
#include <string>

using namespace std;

class NavigationStack
{
    private:
        string Arr[50];
        int iTop;

    public:

        NavigationStack()
        {
            iTop = -1;
        }

        void Push(string strPage)
        {
            if(iTop == 49)
            {
                cout << "Stack is Full" << endl;
                return;
            }

            iTop++;
            Arr[iTop] = strPage;
        }

        string Pop()
        {
            if(iTop == -1)
            {
                return "";
            }

            string strPage = Arr[iTop];

            iTop--;

            return strPage;
        }

        void Display()
        {
            if(iTop == -1)
            {
                cout << "Stack is Empty" << endl;
                return;
            }

            cout << endl;
            cout << "Navigation History:" << endl;

            for(int i = iTop; i >= 0; i--)
            {
                cout << Arr[i] << endl;
            }
        }

        bool IsEmpty()
        {
            return iTop == -1;
        }
};

#endif