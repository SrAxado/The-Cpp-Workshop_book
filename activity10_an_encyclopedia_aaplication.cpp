#include <iostream>
#include <string>
#include <vector>

#include <typeinfo>

struct AnimalInfo {
  std::string name;
  std::string origin;
  int lifeExpectancy;
  int weight;
};

void PrintAnimalInfo(AnimalInfo animal) {
  std::cout << std::endl << "Name: " << animal.name << std::endl;
  std::cout << "Origin: " << animal.origin << std::endl;
  std::cout << "Life Expectancy: " << animal.lifeExpectancy << " years" << std::endl;
  std::cout << "Weight: " << animal.weight << " Kg" << std::endl << std::endl;
}


class Animal {
  protected:
    AnimalInfo animalInfo;
  
  public:
    Animal(AnimalInfo animal) : animalInfo(animal) {};
    Animal(std::string name, std::string origin, int years, int weight) {
      animalInfo.name = name;
      animalInfo.origin = origin;
      animalInfo.lifeExpectancy = years;
      animalInfo.weight = weight;
    };
    AnimalInfo getAnimalInfo() { return animalInfo; }
};

class Lion: public Animal {
  public:
    Lion(AnimalInfo animal) : Animal(animal) {};
    Lion(std::string name = "Lion", std::string origin = "Africa", int years = 12, int weight = 190)
      : Animal(name, origin, years, weight) {};
};

class Tiger: public Animal {
  public:
    Tiger(AnimalInfo animal) : Animal(animal) {};
    Tiger(std::string name = "Tiger", std::string origin = "Africa", int years = 17, int weight = 220)
      : Animal(name, origin, years, weight) {};
};

class Bear: public Animal {
  public:
    Bear(AnimalInfo animal) : Animal(animal) {};
    Bear(std::string name = "Bear", std::string origin = "America", int years = 20, int weight = 520)
      : Animal(name, origin, years, weight) {};
};


int main() {
  std::vector<Animal*> animals;

  animals.push_back(new Lion());
  animals.push_back(new Tiger("Siberian Tiger", "Asia", 14, 270));
  animals.push_back(new Bear());

  std::cout << std::endl << "**Animal Encyclopedia**" << std::endl << std::endl;

  // for (auto const& animal : animals) {
  //   PrintAnimalInfo(animal->getAnimalInfo());
  // }
  
  std::string option;
  do {
    std::cout << "Select animal for more information" << std::endl;
    for (int i = 0; i < animals.size(); ++i) {
      std::cout << i << ") " << animals[i]->getAnimalInfo().name << std::endl;
    }
    std::cout << "-1) Quit application" << std::endl << std::endl;
    std::cout << "  Enter your option: ";
    // std::cin >> option;
    getline(std::cin, option);
    
    int opt;
    try {
      opt = std::stoi(option);

    } catch (const std::invalid_argument& ia) {
      std::cout << "Invalid option! Please enter a digit between [0 - " << animals.size() - 1 << "] or  -1 to exit" << std::endl << std::endl;
      // break;
    }
    if ((opt) && (opt != -1)) {
      if ((opt >= 0) && (opt < animals.size())) {
        PrintAnimalInfo(animals[opt]->getAnimalInfo());
      } else if (opt >= animals.size()) {
        std::cout << "Invalid option! Please enter a value between [0 - " << animals.size() - 1 << "] or -1 to exit" << std::endl << std::endl;
      }
    }
  } while (option != "-1");

  std::cout << "Exiting!" << std::endl;
}