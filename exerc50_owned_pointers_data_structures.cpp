#include <iostream>
using namespace std;

struct numeric_item {
  int value_;
  numeric_item* next_;
};

struct numeric_list {
  numeric_item* head_;
  public:
    numeric_list(): head_(nullptr) {};
    ~numeric_list();
    void print();
    void add(int v);
    numeric_item* find(int v);
};


int main() {
  numeric_list l;

  for (int i = 1; i < 6; ++i) {
    l.add(i);
  }

  l.print();

  numeric_item* p = l.find(4);
  if (p != nullptr) {
    cout << "found numeric_item 4" << endl;
  }

  return 0;
}

numeric_list::~numeric_list() {
  while (head_ != nullptr) {
    numeric_item* p = head_;
    head_ = head_->next_;
    cout << "deleting " << p->value_ << endl;
    delete p;
  }
  // for (numeric_item* p = head_; p != nullptr; head_ = head_->next_) {
  //   cout << "deleting " << p->value_ << endl;
  //   delete p;
  // }
  // Would it create a new numeric_item* for the next cycle?
}

void numeric_list::print() {
  for (numeric_item* p = head_; p != nullptr; p = p->next_) {
    cout << p->value_ << " ";
  }
  cout << endl;
}

// creates a new numeric_item instance and adds it to the head of the list
void numeric_list::add(int v) {
  numeric_item* newp = new numeric_item;
  newp->value_ = v;
  newp->next_ = head_;
  head_ = newp;
}

numeric_item* numeric_list::find(int v) {
  for (numeric_item* p = head_; p != nullptr; p = p->next_) {
    if (p->value_ == v) {
      return p;
    }
  }
  return nullptr;
}