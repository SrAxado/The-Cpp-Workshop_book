///  C++17 - Implementing a singly linked list with smart pointers
/// Posted on February 22, 2019 by Paul 
/*
https://solarianprogrammer.com/2019/02/22/cpp-17-implementing-singly-linked-list-smart-pointers/

In this tutorial, I will show you how to implement a singly linked list 
data structure in C++17 with smart pointers. This is also useful as an 
exercise in learning about how you can use smart pointers instead of raw 
pointers to manage the memory of the list elements.

A singly linked list is a collection of nodes (elements), in which every 
node contains a data field and a link to the next node. The first node 
of a singly linked list is usually named head or root. The last element 
of the list is usually named tail and his next field links to nothing.
*/
/// Disclaimer: In C++, in almost all cases, you should consider using 
/// a std::vector instead of a list. If you really need a singly linked 
/// list, use std::forward_list.
#include <iostream>
#include <memory>
using namespace std;

struct Node {
  int data;
  unique_ptr<Node> next;
  Node(int data) : data{data}, next{nullptr} {};
  ~Node() {
    cout << "Destroy node with data: " << data << endl;
  }
};

int main () {
  auto n0{make_unique<Node>(0)};
  auto n1{make_unique<Node>(1)};
  n1->next = std::move(n0);

  auto n2{make_unique<Node>(2)};
  n2->next = std::move(n1);

  return 0;
}

/*
Basically, at the end of the main function the first node in the list, 
the head node, which in our manually assembled list is n2 goes out of 
scope, at which point the unique smart pointer that owns the node object 
calls his destructor. Because of the way the nodes are linked, when you 
manually delete or when the head node goes out of scope all the nodes 
in the list are recursively deleted! What do you think will happen 
if you create a large list of nodes, e.g. a few millions of nodes, 
and you delete the header or the header goes out of scope ? Because of 
the recursive destruction of the subsequent nodes there is a good chance 
that you will get a stack overflow error.
*/