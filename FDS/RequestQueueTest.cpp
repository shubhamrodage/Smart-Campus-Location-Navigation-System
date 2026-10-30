#include <iostream>
#include "RequestQueue.h"

using namespace std;

int main()
{
    RequestQueue objQueue;

    cout << "====================================" << endl;
    cout << "       SEARCH REQUEST QUEUE" << endl;
    cout << "====================================" << endl;

    objQueue.Enqueue("Search Location");
    objQueue.Enqueue("Search Faculty");
    objQueue.Enqueue("Search Department");
    objQueue.Enqueue("Search Building");

    objQueue.Display();

    cout << endl;

    cout << "Processed Request: "
         << objQueue.Dequeue() << endl;

    cout << "Processed Request: "
         << objQueue.Dequeue() << endl;

    cout << endl;

    objQueue.Display();

    return 0;
}