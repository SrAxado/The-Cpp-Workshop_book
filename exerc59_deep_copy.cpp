// Constructor -- Deep copy
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Track {
  public:
    // copy constructor that performs a shallow copy
    // Track(float lengthInSeconds = 0.0f, string trackName = "not set", const char* newData = NULL) {
    //   m_lengthInSeconds = lengthInSeconds;
    //   m_trackName = trackName;

    //   // delete the array so it can be recreated
    //   delete[] m_data;

    //   // create the sample clip from data
    //   m_dataSize = strlen(newData);
    //   m_data = new char[m_dataSize + 1];
    //   strcpy(m_data, newData);
    // }

    // copy constructor that performs a deep copy
    Track(float lengthInSeconds = 0.0f, string trackName = "not set", 
        string artistName = "not set", const char* data = NULL) {
          m_lengthInSeconds = lengthInSeconds;
          m_trackName = trackName;
          m_artistName = artistName;

          // create the sample clip from data
          m_dataSize = strlen(data);
          m_data = new char[m_dataSize + 1];
          strcpy(m_data, data);
    }

    ~Track() {
      delete[] m_data;
    }

    void SetData(float lengthInSeconds, string trackName = "not set", const char* newData = NULL) {
      m_lengthInSeconds = lengthInSeconds;
      m_trackName = trackName;

      // delete the array so it can be recreated
      // delete[] m_data;

      // create the sample clip from data
      m_dataSize = strlen(newData);
      m_data = new char[m_dataSize + 1];
      strcpy(m_data, newData);
    }
    

    // m_ prefix added to member variables, to avoid naming conflicts with parameter names
    float m_lengthInSeconds;
    string m_trackName;

    // additional artist name string member variable
    string m_artistName;

    // sample clip data
    int m_dataSize;
    char* m_data;
};

//   since the Track class does not have a user-defined copy constructor that correctly executes a deep copy,
// it deletes the same m_data variable used by the passed-in object
// void PrintTrackName(Track track) {
// by not creating a copy of the track, no destructor will be called
void PrintTrackName(Track &track) {
  cout << "Track Name: " << track.m_trackName << endl;
}

int main() {
  Track track(200.0f, "Still Alive", "GlaDos", "f651270d6011098375db09912b03e5e7");
  
  // copy the first track with the artist name
  Track track2 = track;
  // set the new needed data
  track2.SetData(300.0f, "Want You Gone", "db6fd7d74393b375344010a0c9cc4535");

  PrintTrackName(track);
  cout << "Track 1" << endl;
  cout << "Track Name: " << track.m_trackName << endl;
  cout << "Track Length: " << track.m_lengthInSeconds << endl;
  cout << "Track Data: " << track.m_data << endl;
  cout << endl;

  cout << "Track 2" << endl;
  cout << "Track Name: " << track2.m_trackName << endl;
  cout << "Track Length: " << track2.m_lengthInSeconds << endl;
  cout << "Track Data: " << track2.m_data << endl;
  cout << endl;

  return 0;
}