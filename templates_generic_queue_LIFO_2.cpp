/*

LIFO
+--------+--------+--------+--------+--------+--------+--------+--------+
|    n   |  n - 1 |  n - 2 |  ...   |    2   |    1   |  ...   |        |
+--------+--------+--------+--------+--------+--------+--------+--------+
^                                                     ^                 ^
queueDataEnd                                    queueData           memLimit

*/

#include <iostream>
#include <memory>

using namespace std;

template<class T>
class Queue {
  public:
    Queue() { init(); }  // the default constructor that creates an empty queue
    // the constructor takes a size and allocates enough memory to store that many elements of T
    // (the explicit keyword is used to ensure that the compiler cannot implicitly construct this type 
    // to convert to another if passed as a parameter)
    explicit Queue(size_t numElements, const T& initialValue = T()) { init(numElements, initialValue); }
    Queue(const Queue& q) { init(q.top(), q.bottom()); }  // copy constructor

    // assingment operator overload
    // Queue& operator=(const Queue& rhs) {
    //   if (&rhs != this) {
    //     destroy();
    //     initi(rhs.top(), rhs.bottom());
    //   }
    //   return *this;
    // }

    // ~Queue() { destroy(); }

    void push(const T& element) {
      if (queueData == memLimit) {
        resize();
      }
      append(element);
    }


    T* top() const { return queueData - 1; }
    T* bottom() const { return queueDataEnd; }

    void displayMemInfo() const {
      cout << "QueueData: " << queueData << endl;
      cout << "QueueDataEnd: " << queueDataEnd << endl;
      cout << "MemLimit: " << memLimit << endl;
      cout << "ptrdiff_t(1): " << ptrdiff_t(1) << endl;
    }


  private:
    allocator<T> alloc; // the allocator object

    T* queueData; // pointer to one after the top element
    T* queueDataEnd;  // pointer to the beginning of the bottom element
    T* memLimit;  // pointer to one after the last possible element

    void init() { queueData = queueDataEnd = memLimit = 0; }  // defines as if an empty queue

    void init(size_t numElements, const T& initialValue) {
      queueData = alloc.allocate(numElements);
      uninitialized_fill(queueData, queueDataEnd, initialValue);
    }

    
    
    void init(T* bottom, T* top) {
      queueDataEnd = alloc.allocate(top - bottom);
      queueData = unitialized_copy(bottom, top, queueDataEnd);
    }

    void resize() {
      size_t newSize = max(2 * (queueData - queueDataEnd), ptrdiff_t(1));
      T* newData = alloc.allocate(newSize);
      T* newDataTop = uninitialized_copy(queueData, queueDataEnd, newData);
      queueDataEnd = newData;
      queueData = newDataTop;

    }

    void append(const T& newValue) {
      alloc.construct(queueData, newValue);
    }


};



int main() {
  Queue<int> testQueue;

  testQueue.push(1);
  testQueue.push(2);

  testQueue.displayMemInfo();

  cout << *testQueue.top() << endl;
  

  return 0;
}