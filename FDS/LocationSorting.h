#ifndef LOCATIONSORTING_H
#define LOCATIONSORTING_H

#include <iostream>
#include <string>

using namespace std;

class LocationSorting
{
    public:

        void BubbleSort(string Arr[], int iSize)
        {
            for(int i = 0; i < iSize - 1; i++)
            {
                for(int j = 0; j < iSize - i - 1; j++)
                {
                    if(Arr[j] > Arr[j + 1])
                    {
                        string strTemp = Arr[j];

                        Arr[j] = Arr[j + 1];

                        Arr[j + 1] = strTemp;
                    }
                }
            }
        }

        void Display(string Arr[], int iSize)
        {
            for(int i = 0; i < iSize; i++)
            {
                cout << Arr[i] << endl;
            }
        }
};

#endif