// Rodin Ilya 11-1
#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cassert> 
#include <vector>
#include <map>
using namespace std;

struct Node {
  int value;
  char ch;
  int freq;
  Node* left;
  Node* right;
};

struct List {
  Node* root;
};

void buildTree(string text);
