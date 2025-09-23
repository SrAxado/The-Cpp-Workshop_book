// Creating a Class that Prints Values
#include <iostream>
#include <string>
using namespace std;

class ValuePrinter {
  public:
    void Print(string msg, float f) {
      cout << msg << " : " << f << endl;
    }

    void Print(string msg, int i) {
      cout << msg << " : " << i << endl;
    }

    void Print(string msg, string s) {
      cout << msg << " : " << s << endl;
    }
};

class Article {
  string m_title;
  int m_pageCount;
  int m_wordCount;
  string m_author;
  ValuePrinter valuePrinter;
  
  public:
    Article(string title, int pageCount, int wordCount, string author) {
      m_title = title;
      m_pageCount = pageCount;
      m_wordCount = wordCount;
      m_author = author;
    }

    void ShowDetails() {
      valuePrinter.Print("Article Title", m_title);
      valuePrinter.Print("Article Page Count", m_pageCount);
      valuePrinter.Print("Article Word Count", m_wordCount);
      valuePrinter.Print("Article Author", m_author);
    }
};

class Shape {
  string m_type;
  float m_area;
  ValuePrinter valuePrinter;

  public:
    Shape(string type, float area) : m_type(type), m_area(area) {}

    void ShowDetails() {
      valuePrinter.Print("Shape type: ", m_type);
      valuePrinter.Print("Area: ", m_area);
    }
};

int main() {
  Article article("Celebrity Crushes!", 2, 200, "Papa Ratsea");
  article.ShowDetails();

  cout << endl;
  
  Shape square("Square", 16);
  square.ShowDetails();

  return 0;
}