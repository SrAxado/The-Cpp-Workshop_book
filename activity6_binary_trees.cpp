#include <iostream>
using namespace std;

struct numeric_tree {
  int value_;
  numeric_tree* lower_ = nullptr;
  numeric_tree* higher_ = nullptr;
};

numeric_tree* root = nullptr;

// whenever it adds a new node it will always be a leaf
void add(int number, numeric_tree** head) {
  // numeric_tree** where_to_place = find_node(number, head);

  numeric_tree** where_to_place = head;
  numeric_tree* tmp = new numeric_tree;

  tmp->value_ = number;
  tmp->lower_ = nullptr;
  tmp->higher_ = nullptr;

  while ((*where_to_place) != nullptr && (*where_to_place)->value_ != number) {
    if ((*where_to_place)->value_ < number) {
      where_to_place = &((*where_to_place)->higher_);
    } else {
      where_to_place = &((*where_to_place)->lower_);
    }
  }

  if (*where_to_place == nullptr) {
    *where_to_place = tmp;
  } else if ((*where_to_place)->value_ == number) {
    cout << number << ": already belongs to the tree" << endl;
  }
}

/// BOOK SOLUTION
///
// void add(int v, numeric_tree** pp) {
//   *pp = new numeric_tree;
//   (*pp)->value_ = v;
//   (*pp)->lower_ = (*pp)->higher_ = nullptr;
// }

// A much more elegant solution!
// -- add(value, find(value)) --> makes use of the find function
//     (I did the same.. ending up having a copy of the find function inside the add function)
// -- it doesn't protect for already existent values



// numeric_tree** find_node(int number, numeric_tree** branch) {
//   while ((*branch) != nullptr && (*branch)->value_ != number) {
//     if ((*branch)->value_ < number) {
//       branch = &((*branch)->higher_);
//     } else {
//       branch = &((*branch)->lower_);
//     }
//     // if ((*branch)->value_ > number) {
//     //   branch = &((*branch)->lower_);
//     // } else if ((*branch)->value_ < number) {
//     //   branch = &((*branch)->higher_);
//     // } else {
//     //   return branch; // value_ equals number
//     // }
//   }
//   // either found a nullptr to place the number or returns the node with the same number
//   return branch;
// }

void delete_tree(numeric_tree** branch) {
  while (((*branch)->lower_ != nullptr) || ((*branch)->higher_ != nullptr)) {
    if ((*branch)->lower_ != nullptr) {
      delete_tree(&((*branch)->lower_));
    } else {
      // branch->higher_ != nullptr
      delete_tree(&((*branch)->higher_));
    }
  }
  // delete (*branch);

  // while ((branch->lower_ != nullptr) && (branch->higher_ != nullptr)) {
  //   if (branch->lower_ != nullptr) {
  //     delete_tree(branch->lower_);
  //   } else {
  //     delete_tree(branch->higher_); // branch->higher_ != nullptr
  //   }
  // }

  numeric_tree** tmp = branch;
  (*branch) = nullptr;
  delete (*tmp);
}

/// BOOK SOLUTION
///
// void delete_tree(numeric_tree* item) {
//   if (item == nullptr) {
//     return;
//   } else {
//     delete_tree(item->lower_);
//     delete_tree(item->higher_);
//     cout << "deleting " << item->value_ << endl;
//     delete item;
//   }
// }

// I didn't make a good use of the recursion!
// The while loop is unnecessary, the recursion will do its work
// -- the book solution deletes the tree indiscriminately (as it's suppose to be!)


numeric_tree** find(int number, numeric_tree** branch) {
  if ((*branch) != nullptr) {
    if ((*branch)->value_ > number) {
      return find(number, &(*branch)->lower_);
    } else if ((*branch)->value_ < number) {
      return find(number, &((*branch)->higher_));
    } else {
      if ((*branch)->value_ == number) {
        return branch;
      } else {
        return nullptr;
      }
    }
  }
  return nullptr;
}

/// BOOK SOLUTION
///
// numeric_tree** find(int v, numeric_tree** pp) {
//   if (*pp == nullptr) {
//     return pp;
//   } else if (v < (*pp)->value_) {
//     return find(v, &((*pp)->lower_));
//   } else {
//     return find(v, &((*pp)->higher_));
//   }
// }

// A much more elegant solution, making good use of the recursive resource.
// One could easily add the verification of an existing value not allowing duplicates in the tree


void print(numeric_tree** branch) {
  if ((*branch)->lower_ != nullptr) {
    print(&(*branch)->lower_);
  }

  if ((*branch)->value_ )
  cout << (*branch)->value_ << " (" << (*branch) << ") -- ";
  
  if ((*branch)->higher_ != nullptr) {
    print(&((*branch)->higher_));
  }
}

void print2(numeric_tree* branch) {
  if (branch->lower_ != nullptr) {
    print2(branch->lower_);
  }


  // branch->value_ is an integer
  if (branch->value_ == (int) branch->value_) {
    cout << branch->value_ << " (" << branch << ") -- ";
  }

  if (branch->higher_ != nullptr) {
    print2(branch->higher_);
  }
}
// void print2() {
//   for (numeric_tree* p = root; p != nullptr; p = p->next_) {
//     cout << p->value_ << " ";
//   }
//   cout << endl;
// }

/// BOOK SOLUTION
///
// void print(numeric_tree* item) {
//   if (item == nullptr) {
//     return;
//   } else {
//     print(item->lower_);
//     cout << item->value_ << " ";
//     print(item->higher_);
//   }
// }

// Again, the book solution is much more elegant and simple
// One shouldn't verify the state of the node, instead should conduct the path so that it would flow through all the tree

int main() {
  numeric_tree** four = nullptr;


  add(3, &root);
  add(5, &root);
  add(2, &root);
  add(1, &root);
  add(6, &root);
  add(4, &root);
  add(2, &root);

  cout << "Just to check: root --> " << root << endl;

  // print(&root);
  print2(root);
  cout << endl;

  four = find(4, &root);
  if (four != nullptr) {
    cout << "Thist is the address of the 4 node: " << *four << endl;
    cout << "Just to certify: value_ = " << (*four)->value_ << endl;
  } else {
    cout << "The node with the number 4 does not exist" << endl;
  }

  delete_tree(&root);
  cout << "Just to check: root --> " << root << endl;

  return 0;
}


/// BOOK SOLUTION
///
// int main() {
//   int insert_order[] {4, 2, 1, 3, 6, 5};
//   for (int i = 0; i < 6; ++i) {
//     int v = insert_order[i];
//     add(v, find(v, &root));
//   }

//   print(root);
//   cout << endl;

//   delete_tree(root);

//   return 0;
// }