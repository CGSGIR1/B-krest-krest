#pragma once
// Rodin Ilya 10-1
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

struct Node {
  int value;
  Node* next;
  Node* prev;
};

struct List {
  Node* head;
  Node* tail;
};

List* create_list();
void display(List* list);
void display_reverse(List* list);
void add_front(List* list, int value);
void add_back(List* list, int value);
int remove_front(List* list);
int remove_back(List* list);
double averagen(List* list);
