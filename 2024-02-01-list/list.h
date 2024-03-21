#pragma once
#include <iostream>

struct Node {
    double value;
    Node* next;
};

void add(Node** list, double nvalue);
void add_tail(Node** list, double nvalue);
void display(Node** list);
double Average(Node** list);
Node** find(Node** list, double value);
Node* find(Node* list, double value);
void remove(Node** list, double x);
void remove(Node** list, double x);
