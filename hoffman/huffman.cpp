// Rodin Ilya 11-1
#include "huffman.h"

List* create_list() {
  List* tmp = new List;
  tmp->root = nullptr;
  return tmp;
}

Node* new_node(char ch, int freq, Node* left, Node* right)
{
  Node* node = new Node();

  node->ch = ch;
  node->freq = freq;
  node->left = left;
  node->right = right;

  return node;
}

void encode(Node* root, string str, map<char, string>& codes) {
  if (root == nullptr) {
    return;
  }

  if (!root->left && !root->right) {
    codes[root->ch] = str;
  }

  encode(root->left, str + "0", codes);
  encode(root->right, str + "1", codes);
}

void decode(Node* root, int& index, string str) {
  if (root == nullptr) {
    return;
  }

  if (!root->left && !root->right)
  {
    cout << root->ch;
    return;
  }

  if (str[++index] == '0') {
    decode(root->left, index, str);
  } else {
    decode(root->right, index, str);
  }
}

bool cmp(Node *a, Node *b) {
  return a->freq > b->freq;
}

void buildTree(string text)
{
  map<char, int> freq;
  for (char ch : text) {
    freq[ch]++;
  }
  vector<Node*> queue;
  for (auto pair : freq) {
    queue.push_back(new_node(pair.first, pair.second, nullptr, nullptr));
  }
  sort(queue.begin(), queue.end(), cmp);
  for (auto pair : queue) {
    cout << pair->ch << ": " << pair->freq << endl;
  }

  while (queue.size() != 1)
  {
    Node* left = queue[queue.size() - 1];
    queue.pop_back();
    Node* right = queue[queue.size() - 1];
    queue.pop_back();

    int sum = left->freq + right->freq;
    queue.push_back(new_node('\0', sum, left, right));
    sort(queue.begin(), queue.end(), cmp);
  }
  Node* root = queue[0];

  map<char, string> codes;
  encode(root, "", codes);

  cout << "Codes are :\n" << '\n';
  for (auto pair : codes) {
    cout << pair.first << " " << pair.second << '\n';
  }

  cout << "\nOriginal string was :\n" << text << '\n';

  string str = "";
  for (char ch : text) {
    str += codes[ch];
  }

  cout << "\nEncoded string is :\n" << str << '\n';

  int index = -1;
  cout << "\nDecoded string is: \n";
  while (index < (int)str.size() - 2) {
    decode(root, index, str);
  }
}
