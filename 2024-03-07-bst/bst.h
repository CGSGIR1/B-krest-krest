#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

struct Node {
  int value;
  Node* left;
  Node* right;
};

struct List {
  Node* root;
};

List* create_list();
int add_elem(List *list,int x);
void display(List* list);
int remove_elem(List* list, int x);
void display2(List* list);