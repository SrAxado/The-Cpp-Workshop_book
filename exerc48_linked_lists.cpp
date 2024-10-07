// Linked Lists of Class Instances
#include <iostream>
using namespace std;

struct numeric_item {
  int value_;
  numeric_item* next_;
};

numeric_item* head = nullptr;

void print() {
  for (numeric_item* p = head; p != nullptr; p = p->next_) {
    cout << p->value_ << " ";
  }
  cout << endl;
}

void add(int v, numeric_item** pp) {
  numeric_item* newp = new numeric_item;
  newp->value_ = v;

  newp->next_ = *pp;
  *pp = newp;
}

void delete_list(numeric_item* head) {
  while (head != nullptr) {
    numeric_item* p = head;
    head = head->next_;
    cout << "deleting " << p->value_ << endl;
    delete p;
  }
};

numeric_item** find(int v, numeric_item** pp) {
  while ((*pp) != nullptr && (*pp)->value_ != v) {
    pp = &((*pp)->next_);
  }
  
  return pp;
}


int main() {
  for (int i = 1; i < 10; i = i + 2) {
    add(i, &head);
  }

  numeric_item** pp;

  pp = find(5, &head);
  add(8, pp);
  print();

  add(0, find(-1, &head));
  print();

  delete_list(head);

  return 0;
}