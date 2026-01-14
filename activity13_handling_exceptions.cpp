#include <iostream>
#include <exception>

using namespace std;

bool reactor_safety_check() {
  static int count = 0;
  ++count;

  if (count % 17 == 0) {
    throw runtime_error("Sensor glitch");
  
  } else if (count % 69 == 0) {
    throw 123;
    // throw exception();
  
  } else if (count % 199 == 0) {
    return false;
  }

  return true;
}

void SCRAM() {
  cout << "SCRAM! I mean it. Get away from here!" << endl;
}


int main() {
  bool continue_flag;

  do {
    try {
      continue_flag = reactor_safety_check();
    }
    catch (runtime_error& e) {
      cout << "caught runtime error " << e.what() << endl;
    }
    catch (exception& e) {
      cout << "caught unknown exception type" << endl;
      SCRAM();
      break;
      // continue_flag = false;
    }
    catch (...) {
      cout << "caught unknown exception type" << endl;
      SCRAM();
      break;
      // continue_flag = false;
    }
  } while (continue_flag == true);

  cout << "main() exiting" << endl;

  return 0;
}


/*
OUTPUT:

caught runtime error Sensor glitch
caught runtime error Sensor glitch
caught runtime error Sensor glitch
caught runtime error Sensor glitch
caught unknown exception type
SCRAM! I mean it. Get away from here!
main() exiting


*/