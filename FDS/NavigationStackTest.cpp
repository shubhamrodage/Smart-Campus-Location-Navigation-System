#include <iostream>
#include "NavigationStack.h"

using namespace std;

int main()
{
    NavigationStack objStack;

    cout << "====================================" << endl;
    cout << "      NAVIGATION STACK TEST" << endl;
    cout << "====================================" << endl;

    objStack.Push("Dashboard");
    objStack.Push("Location");
    objStack.Push("Faculty");
    objStack.Push("Navigation");

    objStack.Display();

    cout << endl;

    cout << "Last Visited Page: "
         << objStack.Pop() << endl;

    cout << "Last Visited Page: "
         << objStack.Pop() << endl;

    cout << endl;

    if(objStack.IsEmpty())
    {
        cout << "Stack is Empty" << endl;
    }
    else
    {
        cout << "Stack is Not Empty" << endl;
    }

    return 0;
}