//Programmer : Yang Li
//Programmer's ID: 1494803
#include <iostream>
using namespace std;

#include <cassert>

#include "Stack.h"
#include "Stack.h"//ifndef test

int main()
{
  // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << endl;

  Stack<int>a;
  //Testing push function
  cout << "\nTesting void Stack<V>::push(const V& value)\n";
  a.push(11);
  cout << "Expected top: 11" << endl;
  cout << "Actual:" << a.peek() << endl;
  assert(11 == a.peek());
  a.push(22);
  cout << "Expected top: 22" << endl;
  cout << "Actual:" << a.peek() << endl;
  assert(22 == a.peek());
  a.push(33);
  cout << "Expected top: 33" << endl;
  cout << "Actual:" << a.peek() << endl;
  assert(33 == a.peek());

  //Testing pop and peek function
  cout << "\nTesting Stack<V>::pop()";
  cout << "and Stack<V>::peek()"<<endl;
  a.pop();
  cout << "Expected top: 22" << endl;
  cout << "Actual:" << a.peek() << endl;
  assert(22 == a.peek());

  //Testing size and empty function
  cout << "\nTesting int Stack<V>::size()const";
  cout << "and bool Stack<V>::empty()const"<<endl;
  cout << "\nSize expected: 2\n";
  cout << "Actual:" << a.size() << endl;
  assert(2 == a.size());
  a.pop();
  cout << "Expected top: 11" << endl;
  cout << "Actual:" << a.peek() << endl;
  assert(11 == a.peek());
  cout << "Size expected: 1\n";
  cout << "Actual:" << a.size() << endl;
  assert(1 == a.size());
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
  Stack<int> b; b = a;
  cout << "Stack<V>::Stack(const Stack<V>& original)"<<endl;
  b.pop();
  cout << "Expected top: 55" << endl;
  cout << "Actual:" << b.peek() << endl;
  assert(55 == b.peek());
  cout << "\nSize expected: 2\n";
  cout << "Actual:" << b.size() << endl;
  assert(2 == b.size());
  b.pop();
  cout << "Expected top: 44" << endl;
  cout << "Actual:" << b.peek() << endl;
  assert(44 == b.peek());
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
  cout <<"\nTesting void Stack<V>::clear()\n";
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
  const Stack<int>c =a;
  cout <<"\nTesting Stack<V>& Stack<V>::operator=(const Stack<V>& original)\n";
  assert(c.size() == a.size());
  cout << "Size expected: 3\n";
  cout << "Actual:" << c.size() << endl;
  assert(3 == c.size());
}

