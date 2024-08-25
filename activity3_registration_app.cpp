#include <iostream>
#include <vector>
using namespace std;

struct Person {
  // int id;  // unnecessary --> in this example its position in the vector would be the same value
  string name;
  int age;
};

class Db {
  vector<Person> storage;

  public:
    Db() {
      cout << "User SignUp Application" << endl;
    }

    ~Db() {
      storage.empty();
      cout << "Goodbye!" << endl << endl;
    }


    void InputMenu() {
      cout << "Please select an option: " << endl;
      cout << "1: Add Record" << endl;
      cout << "2: Fetch Record" << endl;
      cout << "3: Quit" << endl;
      cout << endl;
      cout << "Enter option: ";
    }

    void GetUserData(Person* tempId) {
      string input;

      // tempId->name = "Zé do Pipo";
      cout << endl << "=== Add User ===" << endl;
      cout << "Please enter user name and age" << endl;
      
      cout << "Name: ";
      getline(cin, tempId->name);

      cout << "Age: ";
      getline(cin, input);
      tempId->age = stoi(input);

      // tempId->id = storage.size();
    }

    int GetUserId() {
      string input;

      cout << endl << "=== Get User Info ===" << endl;
      cout << "User ID: ";
      getline(cin, input);

      return stoi(input);
    }

    void GetUserInfo(int id) {
      if (id < storage.size()) {
        // for (Person info : storage) {
        //   if (info.id == id) {
        //     cout << "User Name: " << info.name << endl;
        //     cout << "User Age: " << info.age << endl;
        //     cout << endl;
        //     break;
        //   }
        // }
        Person info = storage.at(id);
        cout << "User Name: " << info.name << endl;
        cout << "User Age: " << info.age << endl;
        cout << endl;
      } else {
        cout << "Invalid UserID" << endl << endl;
      }
    }

    void MainMenu() {
      string input;
      int option = 0;
      Person tempId;

      while (option != 3) {
        
        InputMenu();
        getline(cin, input);
        option = stoi(input);

        switch (option) {
          case 1:
            GetUserData(&tempId);
            
            storage.push_back(tempId);
            cout << endl << "User record added successfully." << endl << endl;

            break;
          case 2:
            GetUserInfo(GetUserId());
            break;
          case 3:
            // exit(0);
            break;
          default:
            cout << endl << "Please enter a valid option!" << endl << endl;
            break;
        }
      }
    }
};


int main() {

  Db myDb;

  myDb.MainMenu();

  return 0;
}