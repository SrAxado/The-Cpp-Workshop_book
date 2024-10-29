#include <iostream>
#include <memory>
using namespace std;

class word {
  friend class line;
  unique_ptr<char[]> word_;
  int num_spaces_;
  unique_ptr<word> next_;

  public:
    word(char const* str, int spaces, unique_ptr<word> next_word_ptr) : 
      word_(make_unique<char[]>(strlen(str) + 1)),
      num_spaces_(spaces),
      next_(std::move(next_word_ptr)) {
      
      char* dest_ptr = word_.get();
      while (*str) *dest_ptr++ = *str++;
      *dest_ptr = '\0';
    }

    void print() {
      if (word_) cout << word_;
      for (int i = 0; i < num_spaces_; ++i) cout << ' ';
    }

    void get(char* dest_ptr){
      char* word_ptr = word_.get();
      while(*word_ptr) *dest_ptr++ = *word_ptr++;
      for (int i = 0; i < num_spaces_; ++i) *dest_ptr++ = ' ';
      *dest_ptr = '\0';
    }

    ~word() {
      // cout << "Deleting " << word_ << endl;
    }

    int size() {
      char* tmp = word_.get();
      return strlen(tmp) + num_spaces_;
    }
};

class line {
  friend class book;
  unique_ptr<word> head_;
  unique_ptr<line> next_;

  public:
    line(char const* str) {
      int num_spaces;

      for (int i = strlen(str) - 1; i >= 0; --i) {
        num_spaces = 0;
        if (str[i] == ' ') {
          while ((str[i] == ' ') && i >= 0) {
            ++num_spaces;
            --i;
          }
        }

        // int word_end_ptr = i;
        int count_letters = 0;
        while ((str[i] != ' ') && i >= 0) {
          --i;
          ++count_letters;        
        }
        ++i; // points again to the first letter (non space)

        char tmp_buffer[count_letters + 1];
        for (int j = 0; j < count_letters; ++j) {
          tmp_buffer[j] = str[i + j];
        }
        tmp_buffer[count_letters] = '\0';
        
        char* buffer_ptr = tmp_buffer;
        head_ = make_unique<word>(buffer_ptr, num_spaces, std::move(head_));
        // head_ = make_unique<word>(&tmp_buffer[0],num_spaces,std::move(head_));
      }
    }

    ~line(){
      // Unnecessary because where using smart pointers -- have their own destructor
      // unique_ptr<char[]> line_tmp = make_unique<char[]>(50);
      // get(line_tmp.get());
      // cout << "Deleting line: " << line_tmp.get() << endl;
      // cout << "Deleting line [" << this->size() << " length]" << endl;
    }

    void get(char* line_ptr) {
      word* word_ptr = head_.get();

      while (word_ptr) {
        word_ptr->get(line_ptr);
        word_ptr = word_ptr->next_.get();
      }
    }

    void print() {
      word* word_ptr = head_.get();

      while(word_ptr) {
        word_ptr->print();
        word_ptr = word_ptr->next_.get();
      }
    }

    int size() {
      int tmp_size = 0;
      word* word_ptr = head_.get();
      while (word_ptr) {
        tmp_size += word_ptr->size();
        word_ptr = word_ptr->next_.get();
      }
      return tmp_size;
    }
};

class book {
  unique_ptr<line> head_;

  public:
    book() {
    }

    book(char const* str) {
      head_ = make_unique<line>(str);
    }

    ~book() {
      // Since we're using smart pointers, they will destroy themselves when they're no longer used
      // unique_ptr<char[]> tmp = make_unique<char[]>(50);
      // head_->get(tmp.get());
      // cout << "Deleting book: " << tmp << endl;
    }

    void append_pg(char const* page) {
      // cout << '\"' << page << '\"' << endl;
      if (head_.get()) {
        line* last_ptr = head_.get();
        while (last_ptr->next_.get()) last_ptr = last_ptr->next_.get();
      // the compiler doesn't allow to create a unique pointer using an address pointed by a line*
      // hence we use (line*)last_ptr->(unique_ptr<line>)next_ to create a new unique pointer
        last_ptr->next_ = make_unique<line>(page);

      } else
        head_ = make_unique<line>(page);
    }

    void print() {
      line* line_ptr = head_.get();

      while (line_ptr) {
        cout << "\"";
        line_ptr->print();
        cout << "\"" << endl;
        line_ptr = line_ptr->next_.get();
      }
    }
};


int main() {
  char const* brief_Hamlet_quotation[] = {
    "What a piece of work is man, ",
    " How noble in reason, how infinite in faculty,",
    "In form and moving how express and admirable, ",
    " In action how like an Angel, In apprehension how like a god.",
    "The beauty of the world. The paragon of animals."
  };

  //// TEST BENCH
  // word new_word("Uma palavra", 5);
  // new_word.print_block();
  // unique_ptr<char[]> palavra = make_unique<char[]>(20);
  // new_word.get_block(palavra.get());
  // cout << palavra << endl;
  // line new_line("Uma linha curta");  
  
  book book_Hamlet;

  for (auto line : brief_Hamlet_quotation) {
    // cout << line << endl;
    book_Hamlet.append_pg(line);
  }

  book_Hamlet.print();

  return 0;
}