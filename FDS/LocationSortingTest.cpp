#include <iostream>
#include "LocationSorting.h"

using namespace std;

int main()
{
    LocationSorting objSort;

    string Arr[] =
    {
        "B-305",
        "B-301",
        "B-314",
        "B-307",
        "B-303"
    };

    int iSize = 5;

    cout << "====================================" << endl;
    cout << "       LOCATION SORTING TEST" << endl;
    cout << "====================================" << endl;

    cout << endl;
    cout << "Before Sorting:" << endl;

    objSort.Display(Arr, iSize);

    objSort.BubbleSort(Arr, iSize);

    cout << endl;
    cout << "After Sorting:" << endl;

    objSort.Display(Arr, iSize);

    return 0;
}