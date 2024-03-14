#include "bst.h"

int main() {
  List *list = create_list();
  add_elem(list, 10);
  add_elem(list, 6);
  add_elem(list, 5);
  add_elem(list, 2);
  add_elem(list, 11);
  add_elem(list, 7);
  add_elem(list, 8);
  add_elem(list, 4);
  add_elem(list, 3);
  display2(list);
  remove_elem(list, 6);
  display2(list);
  display(list);
}