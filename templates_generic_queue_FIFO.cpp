#include <iostream>
#include <memory> // will allow us to use uninitialized_fill, unintialized_copy and allocator

using namespace std;

template<class T>
class Queue {
  public:
    // the default constructor that creates an empty queue (first and last elements are both 0)
    Queue() { init(); }
    // the constructor that takes a size value and allocates enough memory to store that many elements of T
    explicit Queue(size_t numElements, const T& initialValue = T()) { init(numElements, initialValue); }
    // the explicit keyword is also used to ensure that the compiler cannot implicitly construct this type 
    // to convert from one type to another if passed as a parameter

    // copy constructor
    Queue(const Queue& q) { init(q.front(), q.back()); }

    // assignment operator overload
    Queue& operator=(const Queue& rhs) {
      if (&rhs != this) {
        destroy();
        init(rhs.front(), rhs.back());
      }
      return *this;
    }

    ~Queue() { destroy(); }

    // pointer to the queue data
    T* front() { return queueData; }
    const T* front() const { return queueData; }
    // pointer to one past the last constructed element decremented by one (in other words, the last constructed element)
    T* back() { return queueDataEnd - 1; } 
    const T* back() const { return queueDataEnd - 1; }
    //// const and non-const member functions allows us to use both const and non-const queues

    size_t size() const {
      // subtracting one pointer from another gives the number of elements between the two pointers locations
      // (this value is of the ptrdiff_t type)
      return queueDataEnd - queueData;
    }

    bool empty() const { return size() == 0; }

    void pop() {
      if (queueData != 0) {
        alloc.destroy(queueData);
        // for (int i = 0; i < size(); ++i) {
        // int i would give a warning about comparing int with size_t (aka long unsigned)
        for (size_t i = 0; i < size(); ++i) {
          queueData[i] = queueData[i + 1];
        }
        queueDataEnd -= 1;
      }
    }

    void push(const T& element) {
      if (queueDataEnd == memLimit) { // if there isn't sufficient space in the allocated memory queue will be resized
        resize();
      }
      append(element);
    }


  private:
    // the allocator object
    allocator<T> alloc;
    
    T* queueData; // pointer to the first element
    T* queueDataEnd;  // pointer to the beginning of last element (one past the last element)
    T* memLimit;  // one past the end of allocated memory


    void init() {
      queueData = queueDataEnd = memLimit = 0;  //// 0 or nullptr??!
    }

    // will allocate sufficient memory to hold numElements of T objects
    void init(size_t numElements, const T& initialValue) {
      queueData = alloc.allocate(numElements);
      // it will point to one past the last constructed element, which is the one past the allocated memory
      queueDataEnd = memLimit = queueData + numElements;
      // uninitialized_fill will copy the initial element to the memory chunk between queueData and queueDataEnd
      uninitialized_fill(queueData, queueDataEnd, initialValue);
    }

    // this overloaded version will allocate memory space and then copy the elements between front and back over it
    void init(T* front, T* back) {
      queueData = alloc.allocate(back - front);
      // the unintialized_copy will copy a range of values [first, last] to an uninitialized memory area
      memLimit = queueDataEnd = uninitialized_copy(front, back, queueData);
    }

    // it will have the responsibility of deallocating memory and destroying any elements in our queue
    void destroy() {
      if (queueData != 0) {
        T* it = queueDataEnd;
        // loops backwards through the constructed elements destroying them
        while (it != queueData) {
          alloc.destroy(--it);  // deprecated since C++17, but still valid in C++14
        }
        // deallocates (memLimit - queueData) T memory
        alloc.deallocate(queueData, memLimit - queueData);
      }
      queueData = queueDataEnd = memLimit = 0;
    }

    // allocates the new memory space, copying the existing data to it, 
    // deletes the old memory space and assigns the pointers queueData and queueDataEnd to the new memory space
    void resize() {
      // calculates how much memory will need to be allocated
      size_t newSize = max(2 * (queueDataEnd - queueData), ptrdiff_t(1));
      // the newSize amount of memory is allocated using the allocator
      T* newData =  alloc.allocate(newSize);
      // the existing queueData is copied into the new memory area
      T* newDataEnd = uninitialized_copy(queueData, queueDataEnd, newData);
      destroy();  // deletes the existing data before reassigning the new pointers
      queueData = newData;
      queueDataEnd = newDataEnd;
      // the allocated memory by design is the double of the existing queueData
      memLimit = queueData + newSize;
    }

    // uses the construct function of the allocator to construct an element in the first available space 
    // in the allocated memory, after the cosntructed elements
    void append(const T& newValue) {
      alloc.construct(queueDataEnd++, newValue);  // deprecated since C++17, but still valid in C++14
    }
};


int main() {

  Queue<int> testQueue;
  testQueue.push(1);
  testQueue.push(2);
  cout << "queue contains values: ";
  for (auto it = testQueue.front(); it != testQueue.back() + 1; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  cout << "queue contains " << testQueue.size() << " elements" << endl;
  testQueue.pop();


  cout << "queue contains values: ";
  for (auto it = testQueue.front(); it != testQueue.back() + 1; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  testQueue.push(9);
  testQueue.push(50);
  for (auto it = testQueue.front(); it != testQueue.back() + 1; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  cout << "queue contains " << testQueue.size() << " elements" << endl;
  testQueue.pop();


  cout << "Is the Queue empty? ";
  testQueue.empty() ? cout << "YES" : cout << "NO";
  cout << endl;

  
  cout << "Value of first element is: " << *testQueue.front() << endl;

  cout << "Value of last element is: " << *testQueue.back() << endl;

  return 0;
}