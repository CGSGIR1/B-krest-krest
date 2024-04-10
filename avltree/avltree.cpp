// Rodin Ilya 10-1
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cassert> 
using namespace std;

struct Node {
  int value;
  int h;
  Node* left;
  Node* right;
};

struct List {
  Node* root;
};

List* create_list() {
  List* tmp = new List;
  tmp->root = nullptr;
  return tmp;
}

_inline int height(Node* t) {
  return t ? t->h : 0;
}

void newheight(Node* t) {
  int hleft = height(t->left);
  int hright = height(t->right);
  t->h = (hleft > hright ? hleft : hright) + 1;
}

int diff(Node* t)
{
  return height(t->right) - height(t->left);
}

Node* right_rotation(Node* t)
{
  Node* left = t->left;
  t->left = left->right;
  left->right = t;
  newheight(t);
  newheight(left);
  return left;
}

Node* left_rotation(Node* t)
{
  Node* right = t->right;
  t->right = right->left;
  right->left = t;
  newheight(t);
  newheight(right);
  return right;
}

Node* balance(Node* t) {
  assert(t != nullptr);
  newheight(t);
  int ndiff = diff(t);
  if (ndiff == -2) {
    Node* B = t->left;
    assert(B != nullptr);
    if (diff(B) > 0) {
      t->left = left_rotation(B);
    }
    return right_rotation(t);
  } else if (ndiff == 2) {
    Node* B = t->right;
    assert(B != nullptr);
    if (diff(B) < 0) {
      t->right = right_rotation(B);
    }
    return left_rotation(t);
  } else {
    return t;
  }
}

Node* tadd_node(Node* t, int val)
{
  if (t == nullptr) {
    return new Node{ val, 1, nullptr, nullptr };
  }
  if (val < t->value) {
    t->left = tadd_node(t->left, val);
  } else {
    t->right = tadd_node(t->right, val);
  }
  return balance(t);
}

void add_node(List* list, int val) {
  list->root = tadd_node(list->root, val);
}

Node* fmin(Node* t)
{
  return t->left ? fmin(t->left) : t;
}

Node* remove_min(Node* t)
{
  if (t->left == nullptr) {
    return t->right;
  }
  t->left = remove_min(t->left);
  return balance(t);
}

Node* tremove_node(Node* t, int k)
{
  if (t == nullptr) {
    return 0;
  }
  if (k < t->value) {
    t->left = tremove_node(t->left, k);
  } else if (k > t->value) {
    t->right = tremove_node(t->right, k);
  } else {
    Node* tleft = t->left;
    Node* tright = t->right;
    delete t;
    if (tright == nullptr) {
      return tleft;
    }
    Node* min = fmin(tright);
    min->right = remove_min(tright);
    min->left = tleft;
    return balance(min);
  }
  return balance(t);
}

void remove_node(List* list, int k) {
  list->root = tremove_node(list->root, k);
}

void tdisplay(Node* node) {
  cout << node->value;
  if (node->left == nullptr && node->right == nullptr) {
    return;
  }
  cout << "(";
  if (node->left == nullptr) {
    cout << "*";
  }
  else {
    tdisplay(node->left);
  }
  cout << ",";
  if (node->right == nullptr) {
    cout << "*";
  }
  else {
    tdisplay(node->right);
  }
  cout << ")";
}

void display(List* list) {
  if (list->root != nullptr) {
    tdisplay(list->root);
  }
  cout << "\n";
}

void tdisplay2(Node* t, int depth) {
  if (t == nullptr) {
    return;
  }
  tdisplay2(t->right, depth + 1);
  cout << string(2 * depth, ' ') << t->value << "\n";
  tdisplay2(t->left, depth + 1);
}

void display2(List* list) {
  if (list->root != nullptr) {
    tdisplay2(list->root, 0);
  }
  cout << "\n";
}

int main()
{
  std::cout << "Hello World!\n";
  List* list = create_list();
  for (int i = 1; i < 11; i++) {
    add_node(list, i);
  }
  display2(list);
  remove_node(list, 8);
  display2(list);
}
