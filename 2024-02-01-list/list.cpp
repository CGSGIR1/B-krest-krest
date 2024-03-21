// Rodin Ilya 10-1

#include "list.h"
using namespace std;


void add(Node** list, double nvalue) {
    Node* elem = new Node{ nvalue, *list };
    *list = elem;
}

void add_tail(Node** list, double nvalue) {
    Node* elem = *list;
    while (elem->next != nullptr) {
        elem = elem->next;
    }
    Node* elemnew = new Node{ nvalue, nullptr };
    elem->next = elemnew;
}

void display(Node** list) {
    Node* elem = *list;
    cout << "{";
    while (elem != 0) {
        cout << elem->value << ", ";
        elem = elem->next;
    }
    cout << "}\n";
}

double Average(Node** list) {
    double avr = 0;
    int count = 0;
    Node* elem = *list;
    while (elem != 0) {
        count++;
        avr += elem->value;
        elem = elem->next;
    }
    avr = avr / count;
    cout << avr << "\n";
    return avr;
}

Node** find(Node** list, double value) {
    Node* elem = *list;
    while (elem != 0) {
        if (elem->value == value) {
            cout << "Elem found\n";
            return &elem;
        }
        elem = elem->next;
    }
    cout << "Not found\n";
    return nullptr;
}

Node* find(Node* list, double value) {
    Node* elem = list;
    while (elem != 0) {
        if (elem->value == value) {
            cout << "Elem found\n";
            return elem;
        }
        elem = elem->next;
    }
    cout << "Not found\n";
    return nullptr;
}

void remove(Node** list, double x) {
    Node* elem = *list;
    Node* elemold = *list;
    while (elem != 0) {
        if (elem->value == x) {
            cout << "Elem removed\n";
            elemold->next = elem->next;
            delete elem;
            return;
        }
        elemold = elem;
        elem = elem->next;
    }
    cout << "Not found\n";
}
