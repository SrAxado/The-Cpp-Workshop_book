///  C++17 - Implementing a singly linked list with smart pointers
/// Posted on February 22, 2019 by Paul 
/// https://solarianprogrammer.com/2019/02/22/cpp-17-implementing-singly-linked-list-smart-pointers/
/*
In a singly linked list you really want to insert/remove elements to the 
head of the list for performance reasons, this is an O(1) operation. 
Technically, it is possible to insert a new node at some position in the 
list or at the end, but because of the way we traverse the list, by 
going through all previous elements, this is an O(n) operation that we 
usually want to avoid.
*/

#include <iostream>
#include <memory>
using namespace std;

struct Node {
  int data;
  unique_ptr<Node> next;

  Node(int data) : data{data}, next{nullptr} {};
  ~Node() {
    // cout << "Destryoing Node(" << data << ")" << endl;
  }
};

struct List {
  public:
    List() : head{nullptr} {};

    List(const List &list) {
      Node *root = list.head.get();

      unique_ptr<Node> new_head{nullptr};
      Node *pnew_head{nullptr};
      
      while(root) {
        auto temp{make_unique<Node>(root->data)};
        if (new_head == nullptr) {
          new_head = std::move(temp);
          pnew_head = new_head.get();
        } else {
          pnew_head->next = std::move(temp);
          pnew_head = pnew_head->next.get();
        }
        root = root->next.get();
      }
      head = std::move(new_head);
    }

    List(List &&list) {
      head = std::move(list.head);
    }

    ~List() {
      clean();
    }

    void clean() {
      while (head) {
        head = std::move(head->next);
      }
    }

    friend ostream& operator<<(ostream &os, const List &list);

    void push(int data) {
      auto temp{make_unique<Node>(data)};
      if (head) {
        temp->next = std::move(head);
        head = std::move(temp);

      } else {
        head = std::move(temp);
      }
    }

    void pop () {
      if (head == nullptr) {
        return;
      }

      unique_ptr<Node> temp = std::move(head);
      head = std::move(temp->next);
    }

  void reverse() {
    List tmp;
    Node *root = head.get();

    while (root) {
      tmp.push(root->data);
      root = root->next.get();
    }
    clean();
    head = std::move(tmp.head);
  }

  private:
    unique_ptr<Node> head;
};

ostream& operator<<(ostream &os, const List &list) {
  Node *head = list.head.get();
  while (head) {
    os << head->data << ' ';
    head = head->next.get();
  }
  return os;
}


int main() {
  List list;

  cout << "The list is empty: " << list << endl;

  for (int i = 0; i < 10; ++i) {
    list.push(i);
  }

  cout << "The list has 10 nodes: " << list << endl;

  list.pop();
  list.pop();
  list.pop();

  cout << "The list after 3 pops: " << list << endl;

  list.push(-20);
  list.push(-30);
  cout << "The list after 2 pushes: " << list << endl;

  // list.clean();
  // cout << "The list after clean(): " << list << endl;

  List list2 = list;
  cout << "This is list2: " << list2 << endl;

  List list3 = std::move(list);
  cout << "list : " << list << endl;
  cout << "list3: " << list3 << endl;

  list3.reverse();
  cout << "list3 reversed: " << list3 << endl;

  return 0;
}