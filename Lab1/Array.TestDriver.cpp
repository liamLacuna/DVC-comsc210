// Programmer: Yang Li
// Programmer's ID: 1494803
#include <iostream>
using namespace std;

#include <cassert>

class Array
{
  int values[100];
  int dummy;

  public:
  int capacity() const {return 100;}
  int operator[ ](int) const;
  int& operator[ ](int);
};

int main()
{
  Array a;

   // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << endl;


  // testing Array::capacity
  cout << "\nTesting Array::capacity\n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " << a.capacity() << endl;
  assert(100 == a.capacity());

// testing the Array::operator[ ] setter
  a[6] = 12356;
  a[7] = 7654321;
  cout << "\nTesting Array::operator[ ] setter\n";
  cout << "EXPECTED: 12356 for a[6]\n";
  cout << "ACTUAL: " << a[6] << endl;
  assert(12356 == a[6]);
  cout << "EXPECTED: 7654321 for a[7]\n";
  cout << "ACTUAL: " << a[7] << endl;
  assert(7654321 == a[7]);
  a[-1000] = 123123;
  cout << "EXPECTED: 123123 for a[-1000]\n";
  cout << "ACTUAL: " << a[-1000] << endl;
  assert(12356 == a[6]);
  assert(7654321 == a[7]);
  assert(123123 == a[-6]); // any out-of-range uses dummy
  assert(123123 == a[100]); // checks upper end of range
  assert(123123 != a[9]); // checks upper end of range
  assert(123123 != a[0]); // checks lower end of range

   // testing the Array::operator[ ] getter
  const Array b = a;
  cout << "\nTesting Array::operator[ ] getter\n";
  cout << "EXPECTED: 12356 for b[6]\n";
  cout << "ACTUAL: " << b[6] << endl;
  assert(12356 == b[6]);
  cout << "EXPECTED: 7654321 for b[7]\n";
  cout << "ACTUAL: " << b[7] << endl;
  assert(7654321 == b[7]);
  cout << "EXPECTED: -999 for b[-1000]\n";
  cout << "ACTUAL: " << b[-1000] << endl;
  assert(12356 == b[6]);
  assert(7654321 == b[7]);
  assert(-999 == b[-6]); // any out-of-range uses dummy
  assert(-999 == b[100]); // checks upper end of range
  assert(-999 != b[9]); // checks upper end of range
  assert(-999 != b[0]); // checks lower end of range

   // const object copy test
  assert(a.capacity() == b.capacity());
  for (int i = 0; i < 100; i++)
    assert(a[i] == b[i]);

  // object assignment test
  Array c; c = a;
  assert(a.capacity() == c.capacity());
  for (int i = 0; i < 100; i++)
    assert(a[i] == c[i]);

  return 0;
}

int Array::operator[ ](int index) const
{
  if (index < 0) return -999;
  if (index >= 100) return -999;
  return values[index];
}

int& Array::operator[ ](int index)
{
  if (index < 0) return dummy;
  if (index >= 100) return dummy;
  return values[index];
}
