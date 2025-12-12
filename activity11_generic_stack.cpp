/*

STACK ---    LIFO
+--------+--------+--------+--------+--------+--------+
|    1   |    2   |    3   |  ...   | n - 1  |    n   |
+--------+--------+--------+--------+--------+--------+
^                                                     ^
queueDataEnd                                         queueData
(bottom)                                             (top)

*/

#include <iostream>
#include <memory> // will allow us to use uninitialized_fill, unintialized_copy and allocator

using namespace std;

template<class T>
class Stack {
  public:
    // the default constructor that creates an empty queue (first and last elements are both 0)
    Stack() { init(); }
    // the constructor that takes a size value and allocates enough memory to store that many elements of T
    explicit Stack(size_t numElements, const T& initialValue = T()) { init(numElements, initialValue); }
    // the explicit keyword is also used to ensure that the compiler cannot implicitly construct this type 
    // to convert from one type to another if passed as a parameter

    // copy constructor
    Stack(const Stack& q) { init(q.bottom(), q.top()); }

    // assignment operator overload
    Stack& operator=(const Stack& rhs) {
      if (&rhs != this) {
        destroy();
        init(rhs.bottom(), rhs.top());
      }
      return *this;
    }

    ~Stack() { destroy(); }

    // pointer to the queue data
    T* bottom() { return queueDataEnd; }
    const T* bottom() const { return queueDataEnd; }
    // pointer to one past the last constructed element decremented by one (in other words, the last constructed element)
    T* top() { return queueData - 1; } 
    const T* top() const { return queueData - 1; }
    //// const and non-const member functions allows us to use both const and non-const queues

    size_t size() const {
      // subtracting one pointer from another gives the number of elements between the two pointers locations
      // (this value is of the ptrdiff_t type)
      return queueData - queueDataEnd;
    }

    bool empty() const { return size() == 0; }

    void pop() {
      if (queueDataEnd != queueData) {
        cout << "Popping element " << *(queueData - 1) << endl;
        queueData -= 1;
        alloc.destroy(queueData);
        // for (int i = 0; i < size(); ++i) {
        // int i would give a warning about comparing int with size_t (aka long unsigned)
        // for (size_t i = 0; i < size(); ++i) {
        //   queueDataEnd[i] = queueDataEnd[i + 1];
        // }
      }
    }

    void push(const T& element) {
      if (queueData == memLimit) { // if there isn't sufficient space in the allocated memory queue will be resized
        resize();
      }
      cout << "Pushing element " << element << endl;
      append(element);
    }

    void printStack() const {
      cout << "The stack contains " << size() << " values: ";
      for (auto it = bottom(); it != top() + 1; ++it) {
        cout << *it << " ";
      }
      cout << endl;
    }

    void printSize() const {
      cout << "The stack contains " << size() << " elements" << endl;
    }


  private:
    // the allocator object
    allocator<T> alloc;
    
    T* queueData; // pointer to the end of the first element of the stack
    T* queueDataEnd;  // pointer to the last element
    T* memLimit;  // one past the end of allocated memory


    void init() {
      queueData = queueDataEnd = memLimit = 0;  //// 0 or nullptr??!
    }

    // will allocate sufficient memory to hold numElements of T objects
    void init(size_t numElements, const T& initialValue) {
      queueDataEnd = alloc.allocate(numElements);
      // it will point to one past the last constructed element, which is the one past the allocated memory
      queueData = memLimit = queueDataEnd + numElements;
      // uninitialized_fill will copy the initial element to the memory chunk between queueDataEnd and queueData
      uninitialized_fill(queueDataEnd, queueData, initialValue);
    }

    // this overloaded version will allocate memory space and then copy the elements between bottom and top over it
    void init(T* bottom, T* top) {
      queueDataEnd = alloc.allocate(top - bottom);
      // the unintialized_copy will copy a range of values [first, last] to an uninitialized memory area
      memLimit = queueData = uninitialized_copy(bottom, top, queueDataEnd);
    }

    // it will have the responsibility of deallocating memory and destroying any elements in our queue
    void destroy() {
      if (queueDataEnd != 0) {
        T* it = queueData;
        // loops backwards through the constructed elements destroying them
        while (it != queueDataEnd) {
          alloc.destroy(--it);  // deprecated since C++17, but still valid in C++14
        }
        // deallocates (memLimit - queueDataEnd) T memory
        alloc.deallocate(queueDataEnd, memLimit - queueDataEnd);
      }
      queueDataEnd = queueData = memLimit = 0;
    }

    // allocates the new memory space, copying the existing data to it, 
    // deletes the old memory space and assigns the pointers queueDataEnd and queueData to the new memory space
    void resize() {
      // calculates how much memory will need to be allocated
      size_t newSize = max(2 * (queueData - queueDataEnd), ptrdiff_t(1));
      // the newSize amount of memory is allocated using the allocator
      T* newData =  alloc.allocate(newSize);
      // the existing queueDataEnd is copied into the new memory area
      T* newDataEnd = uninitialized_copy(queueDataEnd, queueData, newData);
      destroy();  // deletes the existing data before reassigning the new pointers
      queueDataEnd = newData;
      queueData = newDataEnd;
      // the allocated memory by design is the double of the existing queueDataEnd
      memLimit = queueDataEnd + newSize;
    }

    // uses the construct function of the allocator to construct an element in the first available space 
    // in the allocated memory, after the cosntructed elements
    void append(const T& newValue) {
      alloc.construct(queueData++, newValue);  // deprecated since C++17, but still valid in C++14
    }
};


int main() {

  Stack<int> testStack;
  testStack.push(16);
  testStack.push(2);
  testStack.push(34);
  testStack.push(7);

  testStack.printStack();
  testStack.printSize();
  
  testStack.pop();
  testStack.printStack();

  testStack.push(9);
  testStack.push(50);

  testStack.printStack();
  
  testStack.pop();
  testStack.printStack();

  cout << "Is the Queue empty? ";
  testStack.empty() ? cout << "YES" : cout << "NO";
  cout << endl;

  
  cout << "Value of bottom element is: " << *testStack.bottom() << endl;

  cout << "Value of top element is: " << *testStack.top() << endl;

  return 0;
}