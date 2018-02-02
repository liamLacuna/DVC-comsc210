//Programmer Name: Yang li
//Programmer's ID: 1494803
#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "StaticArray.h"
#include "StaticArray.h" //ifndef test

int main()
{
  StaticArray <int, 100> a;

  // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << "\n";

  // testing object:int array
  cout << "\nTesting type: int Array\n";

  // testing Array::capacity
  cout << "\nTesting int Array::capacity\n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " << a.capacity() << endl;
  assert(100 == a.capacity());

  // testing the StaticArray::operator[ ] setter
  a[6] = 12356;
  a[7] = 7654321;
  cout << "\nTesting StaticArray<V, CAP>::operator[ ] setter\n";
  cout << "EXPECTED: 12356 for a[6]\n";
  cout << "ACTUAL: " << a[6] << endl;
  assert(12356 == a[6]);
  cout << "EXPECTED: 7654321 for a[7]\n";
  cout << "ACTUAL: " << a[7] << endl;
  assert(7654321 == a[7]);
  a[-1000] = 999;
  cout << "EXPECTED: 999 for a[-1000]\n";
  cout << "ACTUAL: " << a[-1000] << endl;
  assert(12356 == a[6]);
  assert(7654321 == a[7]);
  assert(999 == a[-6]); // any out-of-range uses dummy
  assert(999 == a[100]); // checks upper end of range
  assert(999 != a[99]); // checks upper end of range
  assert(999 != a[0]); // checks lower end of range

  // testing the StaticArray::operator[ ] getter
  const StaticArray<int, 100> b = a;
  cout << "\nTesting StaticArray<V, CAP>::operator[ ] getter\n";
  cout << "EXPECTED: 12356 for b[6]\n";
  cout << "ACTUAL: " << b[6] << endl;
  assert(12356 == b[6]);
  cout << "EXPECTED: 7654321 for b[7]\n";
  cout << "ACTUAL: " << b[7] << endl;
  assert(7654321 == b[7]);
  cout << "EXPECTED: 999 for b[-1000]\n";
  cout << "ACTUAL: " << b[-1000] << endl;
  assert(12356 == b[6]);
  assert(7654321 == b[7]);
  assert(999 == b[-6]); // any out-of-range uses dummy
  assert(999 == b[100]); // checks upper end of range
  assert(999 != b[99]); // checks upper end of range
  assert(999 != b[0]); // checks lower end of range

  // const object copy test
  assert(a.capacity() == b.capacity());
  for (int i = 0; i < 100; i++)
    assert(a[i] == b[i]);

  // object assignment test
  StaticArray<int, 100> c; c = a;
  assert(a.capacity() == c.capacity());
  for (int i = 0; i < 100; i++)
    assert(a[i] == c[i]);

  cout << "\nTesting type: string Array";
  StaticArray<string, 100> s;

  // testing StaticArray<V, CAP>::capacity
  cout << "\nTesting StaticArray<V, CAP>::capacity\n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " << s.capacity() << endl;
  assert(100 == s.capacity());

  // testing the StaticArray<V, CAP>::operator[ ] setter
  s[6] = "computer";
  s[7] = "science";
  cout << "\nTesting StaticArray<V, CAP>::operator[ ] setter\n";
  cout << "EXPECTED: computer for s[6]\n";
  cout << "ACTUAL: " << s[6] << endl;
  assert("computer" == s[6]);
  cout << "EXPECTED: science for s[7]\n";
  cout << "ACTUAL: " << s[7] << endl;
  assert("science" == s[7]);
  s[-1000] = "data";
  cout << "EXPECTED: data for s[-1000]\n";
  cout << "ACTUAL: " << s[-1000] << endl;
  assert("computer" == s[6]);
  assert("science" == s[7]);
  assert("data" == s[-6]); // any out-of-range uses dummy
  assert("data" == s[100]); // checks upper end of range
  assert("data" != s[99]); // checks upper end of range
  assert("data" != s[0]); // checks lower end of range

  // testing the StaticArray<V, CAP>::operator[ ] getter
  const StaticArray<string, 100> st = s;
  cout << "\nTesting StaticArray<V, CAP>::operator[ ] getter\n";
  cout << "EXPECTED: computer for st[6]\n";
  cout << "ACTUAL: " << st[6] << endl;
  assert("computer" == st[6]);
  cout << "EXPECTED: science for st[7]\n";
  cout << "ACTUAL: " << st[7] << endl;
  assert("science" == st[7]);
  cout << "EXPECTED: structure for st[-1000]\n";
  cout << "ACTUAL: " << st[-1000] << endl;
  assert("computer" == st[6]);
  assert("science" == st[7]);
  assert("data" == st[-6]); // any out-of-range uses dummy
  assert("data" == st[100]); // checks upper end of range
  assert("data" != st[99]); // checks upper end of range
  assert("data" != st[0]); // checks lower end of range

  // const object copy test
  assert(s.capacity() == st.capacity());
  for (int j = 0; j < 100; j++)
    assert(s[j] == st[j]);

  // object assignment test
  StaticArray<string, 100> str; str = s;
  assert(s.capacity() == str.capacity());
  for (int j = 0; j < 100; j++)
    assert(s[j] == str[j]);

  cout << "\nTesting type: double Array\n";
  StaticArray <double, 100> d;

  // testing Array::capacity
  cout << "\nTesting double Array<V, CAP>::capacity\n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " << d.capacity() << endl;
  assert(100 == d.capacity());

  // testing the StaticArray::operator[ ] setter
  d[6] = 1.1;
  d[7] = 2.2;
  cout << "\nTesting StaticArray<V, CAP>::operator[ ] setter\n";
  cout << "EXPECTED: 1.1 for d[6]\n";
  cout << "ACTUAL: " << d[6] << endl;
  assert(1.1 == d[6]);
  cout << "EXPECTED: 2.2 for c[7]\n";
  cout << "ACTUAL: " << d[7] << endl;
  assert(2.2 == d[7]);
  d[-1000] = 3.3;
  cout << "EXPECTED: 3.3 for d[-1000]\n";
  cout << "ACTUAL: " << d[-1000] << endl;
  assert(1.1 == d[6]);
  assert(2.2 == d[7]);
  assert(3.3 == d[-6]); // any out-of-range uses dummy
  assert(3.3 == d[100]); // checks upper end of range
  assert(3.3 != d[99]); // checks upper end of range
  assert(3.3 != d[0]); // checks lower end of range

  // testing the StaticArray::operator[ ] getter

  const StaticArray<double, 100> d1 = d;
  cout << "\nTesting StaticArray<V, CAP>::operator[ ] getter\n";
  cout << "EXPECTED: 1.1 for e[6]\n";
  cout << "ACTUAL: " << d1[6] << endl;
  assert(1.1 == d1[6]);
  cout << "EXPECTED: 2.2 for e[7]\n";
  cout << "ACTUAL: " << d1[7] << endl;
  assert(2.2 == d1[7]);
  cout << "EXPECTED: 3.3 for e[-1000]\n";
  cout << "ACTUAL: " << d1[-1000] << endl;
  assert(1.1 == d1[6]);
  assert(2.2 == d1[7]);
  assert(3.3 == d1[-6]); // any out-of-range uses dummy
  assert(3.3 == d1[100]); // checks upper end of range
  assert(3.3 != d1[99]); // checks upper end of range
  assert(3.3 != d1[0]); // checks lower end of range

  // const object copy test
  assert(d.capacity() == d1.capacity());
  for (int x = 0; x < 100; x++)
    assert(d[x] == d1[x]);

  // object assignment test
  StaticArray<double, 100> d2; d2 = d;
  assert(d.capacity() == d2.capacity());
  for (int x = 0; x < 100; x++)
    assert(d[x] == d2[x]);
  return 0;
}

