#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class VideoClip {
  int m_videoLength;
  string m_videoName;
  int m_releaseYear;
  char* m_videoData;

  public:
    VideoClip() {
      m_videoLength = 0;
      m_videoName = "not set";
      m_releaseYear = 0;
      m_videoData = nullptr;
    }

    VideoClip(const int videoLength = 0, const string videoName = "not set", const int releaseYear = 0,
      const char* videoData = NULL) :
        m_videoLength(videoLength), m_videoName(videoName), m_releaseYear(releaseYear) {

          if (videoData != NULL) {
            m_videoData = new char[strlen(videoData) + 1];
            strcpy(m_videoData, videoData);
          }
    }

    // copy constructor -- deep copy
    // called when creating an object from another object that already exists: VideoClip video3 = video1
    VideoClip(VideoClip& videoClip) {
      m_videoLength = videoClip.m_videoLength;
      m_videoName = videoClip.m_videoName;
      m_releaseYear = videoClip.m_releaseYear;

      int videoLength = strlen(videoClip.m_videoData);
      m_videoData = new char[videoLength + 3];
      strcpy(m_videoData, videoClip.m_videoData);
      strcat(m_videoData, "cx"); // adds a copy protection code
    }

    VideoClip operator=(VideoClip& videoClip) {
      if (this != &videoClip) {
        m_videoLength = videoClip.m_videoLength;
        m_videoName = videoClip.m_videoName;
        m_releaseYear = videoClip.m_releaseYear;

        delete[] m_videoData;
        m_videoData = new char[strlen(videoClip.m_videoData) + 1];
        strcpy(m_videoData, videoClip.m_videoData);
        strcat(m_videoData, "cy");  // adds a copy protection code
      }

      return *this;
    }

    ~VideoClip() {
      delete[] m_videoData;
    }

    void ChangeVideoDetails(const int videoLength = 0, const int releaseYear = 0) {
      if (videoLength != 0) m_videoLength = videoLength;
      if (releaseYear != 0) m_releaseYear = releaseYear;
    }

    void PrintVideoDetails() {
      cout << m_videoLength << " " << m_videoName << " ";
      if (m_releaseYear != 0) 
        cout << "(" << m_releaseYear  << ") ";
      cout << m_videoData << endl;
    }

};

void PrintVideoDetails(const char* clipName, VideoClip& videoClip) {
  cout << clipName << ": ";
  videoClip.PrintVideoDetails();
}

int main() {
  VideoClip video1(10, "Halloween", 2019, "djhdhfidghirhgkhrfkghfkg");
  VideoClip video2(50, "The Shining", NULL, "kotriothgrngirgr");
  VideoClip video3 = video1;  // calls the copy constructor
  
  video3.ChangeVideoDetails(20, 1978);

  // video1.PrintVideoDetails();
  // video2.PrintVideoDetails();
  PrintVideoDetails("video1", video1);
  PrintVideoDetails("video3", video3);
  PrintVideoDetails("video2", video2);
  
  video3 = video1;
  PrintVideoDetails("video1", video1);
  PrintVideoDetails("video3", video3);
  PrintVideoDetails("video2", video2);
  video3 = video2;
  PrintVideoDetails("video3", video3);

  return 0;
}


// OUTPUT
// 
// video1: 10 Halloween (2019) djhdhfidghirhgkhrfkghfkg
// video3: 20 Halloween (1978) djhdhfidghirhgkhrfkghfkgcx
// video2: 50 The Shining kotriothgrngirgr
// video1: 10 Halloween (2019) djhdhfidghirhgkhrfkghfkg
// video3: 10 Halloween (2019) djhdhfidghirhgkhrfkghfkgcy
// video2: 50 The Shining kotriothgrngirgr
// video3: 50 The Shining kotriothgrngirgrcy