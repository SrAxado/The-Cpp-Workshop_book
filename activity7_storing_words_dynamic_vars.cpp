#include <iostream>
#include <memory>
#include <cstring>
using namespace std;

class word {
  private:
    unique_ptr<char[]> word_;
    int num_spaces_;
  public:
    unique_ptr<word> next_word;

    char* get() {
      return word_.get();
    }

    word(char* str, int spaces, unique_ptr<word> next_w)
      : word_(make_unique<char[]>(strlen(str) + 1)),  // creates a buffer with the size of str
        num_spaces_(spaces),
        next_word(std::move(next_w))
    {
      strcpy(word_.get(), str);
      // next_word = nullptr;

      // cout << "Creating " << str << " entry" << endl;
    }

    ~word() {
      // cout << "Destroying " << get() << endl;
    }

    void print_block() {
      // if (word_.get() != "\0") {
        cout << word_.get();
      // }
      for (int i = 0; i < num_spaces_; ++i) {
        cout << ' ';
      }
    }

    // char* get_word_block(char* dst_ptr) {
    void get_word_block(char* dst_ptr) {
      char* src_ptr = word_.get();
      // char* dst_ptr = buff_ptr.get();

      for (int letters = 0; letters < strlen(word_.get()); ++letters) 
        *dst_ptr++ = *src_ptr++;

      for (int spaces = 0; spaces < num_spaces_; ++spaces) *dst_ptr++ = ' ';

      *dst_ptr = '\0';

      // return buff_ptr.get();
    }
};

class line {
  // unique_ptr<line> next_line_;
  unique_ptr<word> line_head_;
  friend class book;  // allows friendly classes to have access private elements
  unique_ptr<line> next_line;

  // unique_ptr<word> get_last_word(unique_ptr<word> word) {
  //   if (word.get .next_word != nullptr) {
  //     strcpy()
  //   }
  // }

  public:
    // line* next_line = nullptr;
    // unique_ptr<line> next_line;

    line(char const* str) {
      // line_head_ = nullptr;  // redundant!! Smart pointers already setting the line_head_ to nullptr

      // char* word_tmp = new char[50];
      char word_tmp[50];
      int word_end = 0;
      int line_length = strlen(str) - 1;
      int count = 0;
      // for (int i = 0; i < strlen(str); ++i) {
      // creates the linked word list front to back, ending up like it's written
      for (int i = line_length; i >= 0; --i) {
        // word_tmp = " ";
        count = 0;
        
        if (str[i] == ' ') {  // counts spaces
          while ((str[i - count] == ' ') && (i - count >= 0)) ++count;
        }

        i -= count;
        word_end = i;
        while ((str[i] != ' ') && (i >= 0)) --i;  // finds next space
        
        // char* word_tmp = new char[line_length - i - count + 1];
        // word_tmp[count - i] = '\0';
        // strncpy(word_tmp, str + i + 1, count - i);
        for (int j = 0; j < word_end - i; ++j) word_tmp[j] = str[(i + 1) + j]; // i points to space
        word_tmp[word_end - i] = '\0';
        ++i;  // points i to char not space --> because of next's for i decrease

        if (line_head_ == nullptr)
          line_head_ = make_unique<word>(word_tmp, count, nullptr);
        else
          line_head_ = make_unique<word>(word_tmp, count, std::move(line_head_));
      }

      // delete[] word_tmp;

      // do {
      //   word_tmp = "";

      //   if (str[begin_word] != '\0') {
      //     if (str[begin_word] != ' ') { // finds word
      //       count = begin_word;

      //       while (str[count] != ' ' || str[count] != '\0') ++count;
      //       strncpy(word_tmp, &str[begin_word], count);
      //     }
          
      //     begin_word += count;
      //     count = begin_word;
      //     while(str[count] == ' ' || str[count] != '\0') ++count; // counts spaces

      //     if (strlen(word_tmp) == 0) {
      //       word_tmp = "\0";
      //     }

      //     //  = new word(word_tmp, count);
      //     begin_word += count;
      //   }

      // } while (str[begin_word] == '\0');
    }

    ~line() {}

    void print_line() {
      word* ptr = line_head_.get();

      cout << '\'';
      while (ptr != nullptr) {
        // unique_ptr<char[]> buff_ptr = make_unique<char[]>(20);
        // // char* test = ptr->get_word_block(buff_ptr.get());
        // ptr->get_word_block(buff_ptr.get());
        // cout << "Word print: " << buff_ptr.get() << endl;

        ptr->print_block();
        ptr = ptr->next_word.get();
      }
      cout << '\'' << endl;
    }
};

class book {
  public:
    book(char const* book_lines[], int num_lines) {
      unique_ptr<line> tmp;
      
      for (int line_i = 0; line_i < num_lines; ++line_i) {
        tmp = make_unique<line>(book_lines[line_i]);
        tmp->next_line = std::move(book_head);
        book_head = std::move(tmp);
      }
    }

    book(char const* book_line) {
      if (book_head) {
        add_line(book_line);
      } else {
        book_head = make_unique<line>(book_line);
      }
    }

    ~book() {
      // cout << "Destroying book" << endl;
    }

    void add_line(char const* str) {
      // unique_ptr<line> tmp = make_unique<line>(str);
      line* ptr_last_line = book_head.get();

      while (ptr_last_line->next_line.get() != nullptr) {
        // ptr_last_line = std::move(ptr_last_line->next_line);  // ERROR: unique_ptr<line> to line*
        ptr_last_line = ptr_last_line->next_line.get();
      }

      // ptr_last_line->next_line = std::move(tmp);
      ptr_last_line->next_line = make_unique<line>(str);
    }

    // recursively prints the from last line to the beggining of the linked list
    // (as the lines were inserted at the head of the list (in reverse order, therefore))
    void print_last(line* ptr) {
      if (ptr->next_line) {
        print_last(ptr->next_line.get());
      }
      ptr->print_line();
    }

    void print() {
      line* line_ptr = book_head.get();

      print_last(line_ptr);
      // while (line_ptr) {
      //   line_ptr->print_line();
      //   line_ptr = line_ptr->next_line.get();
      // }
    }
    
  private:
    unique_ptr<line> book_head;
};


int main() {
  // unique_ptr<word> line;
  // auto palavra = new line("Uma palavra");
  // line sentence1("What a piece of work is man, ");
  char const* book_pages[] = {
    "What a piece of work is man,",
    " How noble in reason, how infinite in faculty,",
    "In form and moving how express and admirable,",
    " In action how like an Angel, In apprehension how like a god.",
    "The beauty of the world. The paragon of animals."
  };

  // cout << book_pages.size() << endl;

  // line sentence2(" How noble in reason, how infinite in faculty,");

  // sentence2.print_line();

  // book test_book(" In action how like an Angel, In apprehension how like a god.");
  // test_book.add_line("What a piece of work is man,");
  book test_book(book_pages, 5);
  test_book.print();

  cout << "- - - - - - - - - - - - - - - -" << endl;

  book book_test2("What a piece of work is man,");
  book_test2.add_line(" How noble in reason, how infinite in faculty,");
  book_test2.add_line("In form and moving how express and admirable,");
  book_test2.add_line(" In action how like an Angel, In apprehension how like a god.");
  book_test2.add_line("The beauty of the world. The paragon of animals.");
  book_test2.print();
  

  return 0;
}

// "What a piece of work is man,"
// " How noble in reason, how infinite in faculty,"
// "In form and moving how express and admirable,"
// " In action how like an Angel, In apprehension how like a god."
// "The beauty of the world. The paragon of animals."




/// The best of helps I've found with smart pointers

// struct Node{
//     int val;
//     unique_ptr<Node> next;
//     Node(int v, unique_ptr<Node> n) : val(v), next(std::move(n)) {}
// };

// unique_ptr<Node> reverseList(unique_ptr<Node> head) {
//     unique_ptr<Node> prev{nullptr};
//     unique_ptr<Node> current = std::move(head);
//     while (current) {
//         unique_ptr<Node> temp = std::move(current->next);
//         current->next = std::move(prev);
//         prev = std::move(current);
//         current = std::move(temp);
//     }
//     return prev;
// }

// void testReverseList() {
//     auto n1 = make_unique<Node>(1, nullptr);
//     auto n2 = make_unique<Node>(2, std::move(n1)); 
//     auto n3 = make_unique<Node>(3, std::move(n2)); 
//     auto n4 = make_unique<Node>(4, std::move(n3)); 
//     auto n5 = make_unique<Node>(5, std::move(n4)); 

//     Node* nodePtr = n5.get();
//     cout << "before: " << endl;
//     while(nodePtr) {
//         cout << nodePtr->val << endl;
//         nodePtr = nodePtr->next.get();
//     }

//     auto result = reverseList(std::move(n5));

//     cout << "after: " << endl;
//     nodePtr = result.get();
//     while(nodePtr) {
//         cout << nodePtr->val << endl;
//         nodePtr = nodePtr->next.get();
//     }
// }

//   One thing to notice here is when we want to modify ownership of the pointers (like in 
// the reverseList function) we need to pass in the unique_ptr and give it ownership of it, 
// then we return the ownership of the new head. In other cases we can just use a raw pointer 
// like we do for iterating to print the results.