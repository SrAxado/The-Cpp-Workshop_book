#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(const string& str) {
  // make copy of the string
  string s(str.begin(), str.end());

  // there is a problem with the erase string method, as it doesn't resize the string properly
  // while removing more than one spaces or punctiuation characters
  // -- regarding spaces it doesn't remove any number of space character from the string;
  // -- regarding punctuation it only removes the first punctuation character from the string
  int numSpaces = count_if(s.begin(), s.end(), [](const char& c) { return isspace(c); });
  int numPunct = count_if(s.begin(), s.end(), [](const char& c) { return ispunct(c); });

  // remove any spaces or punctuation
  s.erase(remove_if(s.begin(), s.end(), [](const char& c) {
    return (ispunct(c) || isspace(c));
  }));

  // cout << " Before resizing[" << numSpaces << "-" << numPunct << "]: " << s << endl;

  // resizing the string to the proper number of characters, removing the extra characters left by the erase method
  // (number of spaces and one less number of punctuation characters)
  s.resize(s.size() - (numSpaces + (numPunct ? numPunct - 1 : 0 )));
  
  // cout << "After cleaning[" << numSpaces << "]: " << s << endl;

  // lower case string s
  transform(s.begin(), s.end(), s.begin(), ::tolower);

  // create a reversed version of the string
  string sr(s.rbegin(), s.rend());

  // compare them and return their comparison
  return (s == sr);
}


int main() {
  // string str;
  // getline(cin, str);

  // string str = "Never odd or even";
  string str = "Ag,es -.- s.ega";

  cout << "'" << str << " is a palindrome? " << (isPalindrome(str) ? "YES" : "NO") << endl;

  return 0;
}