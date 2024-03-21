// Rodin Ilya 10-1

#include "list.h"
using namespace std;

int main()
{   
    cout << "Hello World!\n";
    Node* List = 0;
    while (true) {
        cout << "\n0 - exit\n"
            << "1 - add\n"
            << "2 - add_tail\n"
            << "3 - display\n"
            << "4 - average\n"
            << "5 - remove elem\n"
            << "current: ";
        display(&List);
        cout << "Enter command: ";
        string cmd;
        cin >> cmd;
        if (cmd == "0") {
            break;
        }
        else if (cmd == "1") {
            cout << "New elem: ";
            int elem;
            cin >> elem;
            add(&List, elem);
            cout << "\n";
        }
        else if (cmd == "2") {
            cout << "New elem: ";
            int elem;
            cin >> elem;
            add_tail(&List, elem);
            cout << "\n";
        }
        else if (cmd == "3") {
            cout << "List: ";
            display(&List);
            cout << "\n";
        }
        else if (cmd == "4") {
            cout << "Average of all numbers of list: ";
            Average(&List);
            cout << "\n";
        }
        else if (cmd == "5") {
            cout << "Delete elem: ";
            int elem;
            cin >> elem;
            remove(&List, elem);
            cout << "\n";
        }
        else {
            cout << "command error\n";
        }
    }
}
