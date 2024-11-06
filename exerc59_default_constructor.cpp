// Defining a Default Constructor & Shallow copy
#include <iostream>
using namespace std;

class Track {
  public:
    // m_ prefix is a common way to denote a variable as a member variable
    // (to avoid naming conflicts with parameters names)
    float m_lengthInSeconds;
    string m_trackName;

    //   a default constructor is a constructor that takes no parameters, or a constructor
    // where all parameters have default values
    Track() {
      m_lengthInSeconds = 0.0f;
      m_trackName = "not set";
    }

    //  set default values to parameters
    // (any default parameters must come after non-default parameters)
    Track(bool test, float lengthInSeconds = 10.0f, string trackName = "no, not set") {
      m_lengthInSeconds = lengthInSeconds;
      m_trackName = trackName;
    }

    // syntax of a copy constructor => similar to what should be the compiler-generated version
    // Track(const Track& track) {
    //   m_lengthInSeconds = track.m_lengthInSeconds;
    //   m_trackName = track.m_trackName;
    // }
    // It takes a reference to a const parameter ensuring that the copy constructor
    // will not alter the passed-in parameter.

};

int main() {
  Track track(true);
  // Track track(200.0f, "Still Alive");
  Track track2 = track; // copy construct is called -- Shallow copy

  cout << "Track Name: " << track.m_trackName << endl;
  cout << "Track length: " << track.m_lengthInSeconds << endl;

  return 0;
}

// OUTPUT
// 
// Track Name: no, not set
// Track length: 10