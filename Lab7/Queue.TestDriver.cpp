//Programmer : Yang Li
//Programmer's ID: 1494803
#include <iostream>
using namespace std;

#include <cassert>

#include "Queue.h"
#include "Queue.h"//ifndef test

int main()
{
  // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << endl;

  Queue<int> a;
 //Testing push function
  cout << "\nTesting void Queue<V>::push(const V& value)\n";

  a.push(11);
  a.push(22);
  a.push(33);
  cout << "Expected tail: 33" << endl;
  cout << "Actual:" << a.back() << endl;
  assert(33 == a.back());
  cout << "Expected top: 11" << endl;
  cout << "Actual:" << a.front() << endl;
  assert(11 == a.front());
  a.pop();
  cout << "Expected top: 22" << endl;
  cout << "Actual:" << a.front() << endl;
  assert(22 == a.front());
  cout << "Expected tail: 33" << endl;
  cout << "Actual:" << a.back() << endl;
  assert(33 == a.back());
  a.pop();
  cout << "Expected top: 33" << endl;
  cout << "Actual:" << a.front() << endl;
  cout << "Expected tail: 33" << endl;
  cout << "Actual:" << a.back() << endl;
  assert(33 == a.back());
  assert(33 == a.front());

  a.pop();
  a.push(44);
  a.push(55);
  a.push(66);

  //Testing size and empty function
  cout << "\nTesting int Queue<V>::size()const";
  cout << "and bool Queue<V>::empty()const"<<endl;
  cout << "\nSize expected: 3\n";
  cout << "Actual:" << a.size() << endl;
  assert(3 == a.size());
  a.pop();
  cout << "Expected top: 55" << endl;
  cout << "Actual:" << a.front() << endl;
  assert(55 == a.front());
  cout << "Size expected: 2\n";
  cout << "Actual:" << a.size() << endl;
  assert(2 == a.size());
  a.pop();
  a.pop();
  cout << "Size expected: 0\n";
  cout << "Actual:" << a.size() << endl;
  assert(0 == a.size());
  cout << "\nExpected: 1 (True) for empty()\n";
  cout << "Actual:" << a.empty() << endl;
  assert(1 == a.empty());
  a.pop();
  cout << "\nPop one more time, expected size: 0" << endl;
  cout << "Actual:" << a.size() << endl;
  assert(0 == a.size());

  a.push(44);
  a.push(55);
  a.push(66);
  //testing copy constructor
  Queue<int> b; b = a;
  cout <<endl<<"Queue<V>::Queue(const Stack<V>& original)"<<endl;
  b.pop();
  cout << "Expected top: 55" << endl;
  cout << "Actual:" << b.front() << endl;
  assert(55 == b.front());
  cout << "\nSize expected: 2\n";
  cout << "Actual:" << b.size() << endl;
  assert(2 == b.size());
  b.pop();
  cout << "Expected top: 66 " << endl;
  cout << "Actual:" << b.front() << endl;
  cout << "Expected top: 66" << endl;
  cout << "Actual:" << b.back() << endl;
  assert(66 == b.back());
  cout << "Size expected: 1\n";
  cout << "Actual:" << b.size() << endl;
  assert(1 == b.size());
  b.pop();
  cout << "Size expected: 0\n";
  cout << "Actual:" << b.size() << endl;
  assert(0 == b.size());
  cout << "\nExpected: 1 (True) for empty()\n";
  cout << "Actual:" << b.empty() << endl;
  assert(1 == b.empty());
  b.pop();
  cout << "\nPop one more time, expected size: 0" << endl;
  cout << "Actual:" << b.size() << endl;
  assert(0 == b.size());

  a.push(77);
  a.push(88);
  a.push(99);
   //testing clear function
  cout <<"\nTesting void Queue<V>::clear()\n";
  a.clear();
  cout << "Size expected: 0\n";
  cout << "Actual:" << a.size() << endl;
  assert(0 == a.size());
  cout << "\nExpected: 1 (True) for empty()\n";
  cout << "Actual:" << a.empty() << endl;
  assert(1 == a.empty());

  //testing const object copy
  a.push(10);
  a.push(20);
  a.push(30);
  const Queue<int>c =a;
  cout <<"\nTesting Queue<V>& Queue<V>::operator=(const Queue<V>& original)\n";
  assert(c.size() == a.size());
  cout << "Size expected: 3\n";
  cout << "Actual:" << c.size() << endl;
  assert(3 == c.size());
}


