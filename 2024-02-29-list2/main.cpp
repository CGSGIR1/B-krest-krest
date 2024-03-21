#include "list2.h"
int main() {
  List* list = create_list();
  while (true) {
    cout << "\n0 - exit\n"
      << "1 - display\n"
      << "2 - display_reverse\n"
      << "3 - add to head\n"
      << "4 - add to tail\n"
      << "5 - remove front\n"
      << "6 - remove tail\n"
      << "7 - average\n"
      << "current: ";
    cout << "Enter command: ";
    string cmd;
    cin >> cmd;
    if (cmd == "0") {
      break;
    }
    else if (cmd == "3") {
      int x;
      cin >> x;
      add_front(list, x);
    }
    else if (cmd == "4") {
      int x;
      cin >> x;
      add_back(list, x);
    }
    else if (cmd == "5") {
      remove_front(list);
    }
    else if (cmd == "6") {
      remove_back(list);
    }
    else if (cmd == "7") {
      averagen(list);
    }
    else if (cmd == "1") {
      display(list);
    }
    else if (cmd == "2") {
      display_reverse(list);
    }
    else {
      cout << "Incorrect";
    }
  }
}