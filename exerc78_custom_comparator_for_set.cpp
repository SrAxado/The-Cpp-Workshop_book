// A CUSTOM COMPARATOR FOR A SET
// By default, a set will sort elements in ascending order
// In this exercise, we'll create a custom comparison for the set to sort the Person elements by age, in descending order.
#include <iostream>
#include <string>
#include <set>

using namespace std;

class Person {
  private:
    string m_name;
    int m_age;

  public:
    Person(string name, int age) : m_name(name), m_age(age) {}
    string getName() const { return m_name; }
    int getAge() const { return m_age; }
};

struct customComparator {
  bool operator()(const Person& a, const Person& b) const {
    return (a.getAge() > b.getAge());
  }
};

int main() {
  set<Person, customComparator> personSet;
  Person a("Bob", 35);
  Person b("Bob", 25);
  Person c("Quim", 32);
  personSet.insert(a);
  personSet.insert(b);
  personSet.insert(c);

  for (auto person : personSet) {
    cout << person.getAge() << endl;
  }

  return 0;
}

/*
OUTPUT:

35
32
25

*/