// SORTING VECTORS WITH A CUSTOM COMPARISON
#include <iostream>
#include <vector>
#include <algorithm>

class Track {
  public:
    Track(float length, std::string name, int popularity)
      : m_trackLength(length), m_trackName(name), m_popularityRating(popularity) {}
    
    float getLength() const { return m_trackLength; }
    std::string getName() const { return m_trackName; }
    int getPopulariy() const { return m_popularityRating; }

  private:
    float m_trackLength;
    std::string m_trackName;
    int m_popularityRating;
};

bool trackLengthCompare(const Track& t1, const Track& t2) {
  return (t1.getLength() < t2.getLength());
}

bool trackDescLengthCompare(const Track& t1, const Track& t2) {
  return (t1.getLength() > t2.getLength());
}

bool trackPopularityCompare(const Track& t1, const Track& t2) {
  return (t1.getPopulariy() < t2.getPopulariy());
}

bool trackDescPopularityCompare(const Track& t1, const Track& t2) {
  return (t1.getPopulariy() >= t2.getPopulariy());
}

bool trackNameLengthCompare(const Track& t1, const Track& t2) {
  return (t1.getName().size() < t2.getName().size());
}

int main() {
  std::vector<Track> tracks;
  tracks.push_back(Track(199.0f, "God's Plan", 100));
  tracks.push_back(Track(227.0f, "Hold On, We're Going Home", 95));
  tracks.push_back(Track(182.0f, "The Motto", 80));

  // sort(tracks.begin(), tracks.end(), trackLengthCompare);
  sort(tracks.begin(), tracks.end(), trackNameLengthCompare);

  for (auto t : tracks) {
    std::cout << t.getName() << std::endl;
  }

  return 0;
}