#include <iostream>
#include <string>
using namespace std;


class Track {
  public:
    const float MAX_TRACK_LENGTH = 600.0f;

    Track(float lengthInSeconds, string trackName) {
      m_lengthInSeconds = lengthInSeconds;
      m_trackName = trackName;
    }

    // return by value
    float getLength() { return m_lengthInSeconds; }

    // return by reference
    float& getLengthPtr() { return m_lengthInSeconds; }

    string getName() { return m_trackName; }

    void setName(string newTrackName) {
      if (newTrackName.find("S-Club") == string::npos) {
        m_trackName = newTrackName;
      };
    }
    
    void setLength(float newTrackLength) {
      if ((newTrackLength < MAX_TRACK_LENGTH) && (newTrackLength > 0)) {
        m_lengthInSeconds = newTrackLength;
      }
    }

    // float& getLengthInMinutes() {
      // creates a temporary
      // return m_lengthInSeconds / 60.0f;
      // will issue a compiler error:
      // non-const lvalue reference to type 'float' cannot bind to a temporary of type 'float'
    // }  // temporary out of scope

    // a const reference is a reference that is marked as read-only-a-non-modifiable reference
    const float& getLengthRef() { return m_lengthInSeconds; }

    // getLenghtConst is 
    float getLengthConst() const {
      // modify member data in const function
      // m_lengthInSeconds = 10.0f;  // error: cannot assign to non-static data member within const member function 'getLengthConst'
      return m_lengthInSeconds;
    }

    private:
      float m_lengthInSeconds;
      string m_trackName;

};

int main() {
  Track t(260.0f, "Still Alive");

  cout << "My Favourite Song is: " << t.getName() << endl;
  cout << "It is: " << t.getLength() / 60.0f << " minutes long" << endl << endl;

  float tLength = t.getLength();
  tLength = 100.0f;
  cout << "My Favourite Song is: " << t.getName() << endl;
  cout << "It is: " << t.getLength() / 60.0f << " minutes long" << endl << endl;;

  // getLengthPtr returns a reference and can be modified
  t.getLengthPtr() = 100.0f;
  cout << "My Favourite Song is: " << t.getName() << endl;
  cout << "It is: " << t.getLength() / 60.0f << " minutes long" << endl << endl;

  // getLengthPtr returns a reference but this is actually a copy
  float tLengthCpy = t.getLengthPtr();
  tLengthCpy = 200.0f;
  cout << "My Favourite Song is: " << t.getName() << endl;
  cout << "It is: " << t.getLength() / 60.0f << " minutes long" << endl << endl;

  // getLengthPtr now returns a reference and can be modified
  float& tLengthPtr = t.getLengthPtr();
  tLengthPtr = 300.0f;
  cout << "My Favourite Song is: " << t.getName() << endl;
  cout << "It is: " << t.getLength() / 60.0f << " minutes long" << endl << endl;

  // getLengthRef returns a const reference
  const float& tLengthRef = t.getLength();
  // tLengthRef = 100.0f;  // error: cannot assign to variable 'tLengthRef' with const-qualified type 'const float &'
  // t.getLengthRef() = 100.0f;  // same error
  cout << "My Favourite Song is: " << t.getName() << endl;
  cout << "It is: " << t.getLength() / 60.0f << " minutes long" << endl;
  
  // create const Track
  const Track tConst(260.0f, "Barely Alive");
  // error: 'this' argument to member function 'getLength' has type 'const Track', but function is not marked const
  // cout << "It is: " << tConst.getLength() / 60.0f << " minutes long" << endl;
  return 0;
}


// OUTPUT
// 
// My Favourite Song is: Still Alive
// It is: 4.33333 minutes long

// My Favourite Song is: Still Alive
// It is: 4.33333 minutes long

// My Favourite Song is: Still Alive
// It is: 1.66667 minutes long

// My Favourite Song is: Still Alive
// It is: 1.66667 minutes long

// My Favourite Song is: Still Alive
// It is: 5 minutes long

// My Favourite Song is: Still Alive
// It is: 5 minutes long