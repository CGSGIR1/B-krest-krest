#include"list2.h"

List* create_list() {
  List* tmp = new List;
  tmp->head = tmp->tail = nullptr;
  return tmp;
}

void display(List* list) {
  Node* tmp = list->head;
  while (tmp) {
    cout << tmp->value << ' ';
    tmp = tmp->next;
  }
}

void display_reverse(List* list) {
  Node* tmp = list->tail;
  while (tmp) {
    cout << tmp->value << ' ';
    tmp = tmp->prev;
  }
}

void add_front(List* list, int value) {
  Node* tmp = new Node{ value, list->head, nullptr };
  if (tmp == nullptr) {
    exit(1);
  }
  if (list->head != nullptr) {
    list->head->prev = tmp;
  }
  list->head = tmp;

  if (list->tail == nullptr) {
    list->tail = tmp;
  }
}

void add_back(List* list, int value) {
  Node* tmp = new Node{ value, nullptr, list->tail };
  if (tmp == nullptr) {
    exit(3);
  }
  if (list->tail) {
    list->tail->next = tmp;
  }
  list->tail = tmp;

  if (list->head == nullptr) {
    list->head = tmp;
  }
}

int remove_front(List* list) {
  Node* prev;
  int tmp;
  if (list->head == nullptr) {
    exit(2);
  }
  prev = list->head;
  list->head = list->head->next;
  if (list->head) {
    list->head->prev = nullptr;
  }
  if (prev == list->tail) {
    list->tail = nullptr;
  }
  tmp = prev->value;
  delete prev;
  return tmp;
}

int remove_back(List* list) {
  Node* next;
  int tmp;
  if (list->tail == nullptr) {
    exit(4);
  }

  next = list->tail;
  list->tail = list->tail->prev;
  if (list->tail) {
    list->tail->next = nullptr;
  }
  if (next == list->head) {
    list->head = nullptr;
  }
  tmp = next->value;
  delete next;
  return tmp;
}
double averagen(List* list) {
  if (list->head == nullptr) {
    return -1;
  }
  double avr = 0;
  int count = 0;
  Node* elem = list->head;
  while (elem != 0) {
    count++;
    avr += elem->value;
    elem = elem->next;
  }
  avr = avr / count;
  cout << avr << "\n";
  return avr;
}
