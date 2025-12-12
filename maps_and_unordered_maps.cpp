// MAP / UNORDERED MAP
#include <iostream>
#include <map>
#include <unordered_map>


int main() {

  // --- MAP ----
  // Defaul constructor, an empty map
  std::map<int, int> myMap;

  // Constructs a map from a copy of another map
  std::map<int, int> copiedMap(myMap);

  // Constructs a map from a range
  std::map<int, int> rangeMap(copiedMap.begin(), copiedMap.end());

  // Constructs a map using an intializer list
  std::map<int, int> initList = {{1, 2}, {2, 3}, {3, 4}};

  // Inserts an element into the map
  myMap.insert(std::make_pair(1, 2));

  std::map<std::string, std::string> myStringMap = {
    {"Hello", "Hola"}, {"Goodbye", "Adiós"}, {"Programmer", "Programador"}
  };

  for (const auto& loc : myStringMap) {
    std::cout << loc.first << " In Spanish is " << loc.second << std::endl;
  }


  // --- UNORDERED MAP ----
  // Default constructor, with an optional minimum bucket size
  // std::unordered_map(size_type n)
  std::unordered_map<int, int> myUnorderedMap;
  // Constructs an unordered map from a copy of another unordered map
  std::unordered_map<int, int> copiedUnorderedMap(myUnorderedMap);
  // Constructs an unordered map from a range
  std::unordered_map<int, int> rangeunorderedMap(copiedUnorderedMap.begin(), copiedUnorderedMap.end());
  // Constructs a unordered map from an initializer list with an optional minimum bucket size
  // std::unordered_map(initializer_list<value_type> il, size_type n)
  std::unordered_map<int, int> unorderedInitList = {{1, 2}, {2, 3}, {3, 4}};


  myUnorderedMap.insert(std::make_pair(1, 2));

  return 0;
}