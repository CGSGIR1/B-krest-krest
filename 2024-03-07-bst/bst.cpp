#include "bst.h"

List* create_list() {
  List* tmp = new List;
  tmp->root = nullptr;
  return tmp;
}

int add_elem(List* list, int x) {
  if (list->root == nullptr) {
    list->root = new Node{ x, nullptr, nullptr };
  }
  Node* oldtmp = list->root;
  Node* tmp = list->root;
  while (tmp != nullptr) {
    oldtmp = tmp;
    if (x > tmp->value) {
      tmp = tmp->right;
    } else if (x == tmp->value) {
      return 0;
    } else {
      tmp = tmp->left;
    }
  }
  Node* newelem = new Node{x, nullptr, nullptr};
  if (x > oldtmp->value) {
    oldtmp->right = newelem;
  } else {
    oldtmp->left = newelem;
  }
  return 1;
}

int tremove_elem(Node* oldnode, Node* node, int x) {
  if (node == nullptr) {
    return 0;
  }
  if (x == node->value) {
    Node* ptr;
    if (node->left == nullptr && node->right == nullptr) {
      if (x < oldnode->value) {
        oldnode->left = nullptr;
      }
      else {
        oldnode->right = nullptr;
      }
      delete node;
    } else if (node->left != nullptr && node->right == nullptr) {
      if (x < oldnode->value) {
        oldnode->left = node->left;
      }
      else {
        oldnode->right = node->left;
      }
      delete node;
    } else if (node->left == nullptr && node->right != nullptr) {
      if (x < oldnode->value) {
        oldnode->left = node->right;
      }
      else {
        oldnode->right = node->right;
      }
      delete node;
    } else if (node->left != nullptr && node->right != nullptr) {
      Node* ptr1 = node->left;
      //cout << "hi";
      while (ptr1->right != nullptr) {
        ptr1 = ptr1->right;
      }
      ptr1->right = node->right;
      if (x < oldnode->value) {
        oldnode->left = node->left;
      }
      else {
        oldnode->right = node->left;
      }
      delete node;
    }
    return 2;
  }
  if (x > node->value) {
    tremove_elem(node, node->right, x);
  }
  else {
    tremove_elem(node, node->left, x);
  }
  return 1;
}

int remove_elem(List* list, int x) {
  if (list->root != nullptr) {
    return(tremove_elem(list->root, list->root, x));
  }
  return 0;
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
