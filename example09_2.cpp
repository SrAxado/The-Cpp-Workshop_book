#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Track {
  public:
    Track(float lengthInSeconds, string trackName) {
      m_lengthInSeconds = lengthInSeconds;
      m_trackName = trackName;
    }

    // return by value
    float getLength() const { return m_lengthInSeconds; }

    string getName() const { return m_trackName; }

    private:
      float m_lengthInSeconds;
      string m_trackName;

};

class Playlist {
  public:
    void AddTrack(const Track* track) {
      if (any_of(m_tracks.begin(), m_tracks.end(), 
        [&track](const Track* t) {
          return t->getName() == track->getName(); })) {

        cout << "Track: " << track->getName()
          <<  " NOT added as already exists in playlist" << endl << endl;
        } else {
          m_tracks.push_back(track);
          return;
        }
    }

    void RemoveTrack(const string trackName) {
      m_tracks.erase(remove_if(m_tracks.begin(), m_tracks.end(),
        [&trackName](const Track* t) {
          return (t->getName() == trackName);
        }));
    }

    void PrintTracks() const {
      for (auto& track : m_tracks) {
        // round seconds
        int seconds = static_cast<int>(track->getLength());
        cout << track->getName() << " - " << seconds / 60 << ":"
          << seconds % 60 << endl;
      }
      cout << endl;
    }

    void SortAlphabetically(bool reverse) {
      if (reverse) {
        sort(m_tracks.begin(), m_tracks.end(), CompareTrackNamesReverse);
      } else {
        sort(m_tracks.begin(), m_tracks.end(), CompareTrackNames);
      }
    }

    void SortByLength(bool reverse) {
      if (reverse) {
        sort(m_tracks.begin(), m_tracks.end(), CompareTrackLengthsReverse);
      } else {
        sort(m_tracks.begin(), m_tracks.end(), CompareTrackLengths);
      }
    }

  private:
    static bool CompareTrackNamesReverse(const Track* t1, const Track* t2) {
      return (t1->getName() > t2->getName());
    }
    static bool CompareTrackNames(const Track* t1, const Track* t2) {
      return (t1->getName() < t2->getName());
    }
    static bool CompareTrackLengthsReverse(const Track* t1, const Track* t2) {
      return (t1->getLength() > t2->getLength());
    }
    static bool CompareTrackLengths(const Track* t1, const Track* t2) {
      return (t1->getLength() < t2->getLength());
    }

    vector<const Track*> m_tracks;
};

int main() {
  Track t(100.0f, "Donut Plains");
  Track t2(200.0f, "Star World");
  Track t3(300.0f, "Chocolate Island");

  Playlist p;

  p.AddTrack(&t);
  p.AddTrack(&t2);
  p.AddTrack(&t3);
  p.PrintTracks();

  p.AddTrack(&t2);

  p.SortAlphabetically(false);  // sort alphabetically
  p.PrintTracks();

  p.SortAlphabetically(true);  // sort alphabetically reversed
  p.PrintTracks();

  p.SortByLength(false);
  p.PrintTracks();

  p.SortByLength(true);
  p.PrintTracks();

  return 0;
}


// OUTPUT
// 
// Donut Plains - 1:40
// Star World - 3:20
// Chocolate Island - 5:0

// Track: Star World NOT added as already exists in playlist
// Chocolate Island - 5:0
// Donut Plains - 1:40
// Star World - 3:20

// Star World - 3:20
// Donut Plains - 1:40
// Chocolate Island - 5:0

// Donut Plains - 1:40
// Star World - 3:20
// Chocolate Island - 5:0

// Chocolate Island - 5:0
// Star World - 3:20
// Donut Plains - 1:40