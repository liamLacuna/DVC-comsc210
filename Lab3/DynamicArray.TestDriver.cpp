//Programmer : Yang Li
//Programmer's ID: 1494803
#include <iostream>
#include <string>
using namespace std;

#include <cassert>

#include "DynamicArray.h"
#include "DynamicArray.h" //ifndef test

int main()
{
  DynamicArray <int> a;

  // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << "\n";

  // testing int
  cout << "\nTesting type: int DynamicArray\n";

  // testing DynamicArray::capacity and default constructor
  cout << "\nTesting DynamicArray::capacity and ";
  cout << "default constructor \n";
  cout << "EXPECTED: 2\n";
  cout << "ACTUAL: " << a.capacity() << endl;
  assert(2 == a.capacity());

  DynamicArray<int> test(100);
  // testing DynamicArray :: capacity and main constructor
  cout << "Testing DynamicArray::capacity and ";
  cout << "main constructor \n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " <<test.capacity() << endl;

  // testing DynamicArray :: capacity setter-----Lower
  test.capacity(50);
  cout << "Testing DynamicArray::capacity setter ";
  cout << "---------Lower \n";
  cout << "EXPECTED: 50\n";
  cout << "ACTUAL: "<<test.capacity() << endl;
  assert(50 == test.capacity());
  assert(200 != test.capacity());
  assert(400 != test.capacity());

  // testing DynamicArray :: capacity setter-----Higher
  test.capacity(200);
  cout << "Now testing DynamicArray::capacity setter ";
  cout << "---------Higher \n";
  cout << "EXPECTED: 200\n";
  cout << "ACTUAL: "<<test.capacity() << endl;
  assert(200 == test.capacity());
  assert(50 != test.capacity());
  assert(400!= test.capacity());

  // testing the DynamicArray::operator[ ] setter
  a[6] = 12356;
  assert(12 == a.capacity());
  a[7] = 123123;
  assert(12 == a.capacity());
  cout << "\nTesting DynamicArray::operator[ ] setter----auto adjust larger\n";
  cout << "EXPECTED: 12 \n";
  cout << "ACTUAL: "<<a.capacity() <<endl;
  cout << "\nTesting DynamicArray::operator[]\n";
  cout << "EXPECTED: 12356 for a[6]\n";
  cout << "ACTUAL: " << a[6] << endl;
  assert(12356 == a[6]);
  cout << "EXPECTED: 123123 for a[7]\n";
  cout << "ACTUAL: " << a[7] << endl;
  assert(123123 == a[7]);
  a[-1000] = 999;
  assert(12356 == a[6]);
  assert(123123 == a[7]);
  assert(999 != a[0]); //checks lower end of range

  //testing the DynamicArray::copy constructor
  cout << "nTesting DynamicArray::copy constructor\n";
  a[14]=94;
  a[80]=3;
  const DynamicArray<int> b = a;
  cout << "EXPECTED: Capacity of b = 160\n";
  cout << "AUTUAL : "<< b.capacity() <<endl;
  cout << "EXPECTED: 94 FOR b[14]\n";
  cout << "AUTUAL : "<< b[14] <<endl;
  assert(94 == b[14]);
  assert(999 != b[14]);
  assert(3 != b[14]);
  cout << "EXPECTED: 3 FOR b[80]\n";
  cout << "ACUTUAL : "<< b[80] <<endl;
  assert(3 == b[80]);
  assert(999 != b[80]);
  assert(94 !=b[80]);

  // testing the DynamicArray::operator[ ] getter
  cout << "\nTesting DynamicArray::operator[ ] getter\n";
  cout << "EXPECTED: 12356 for b[6]\n";
  cout << "ACTUAL: " << b[6] << endl;
  assert(12356 == b[6]);
  cout << "EXPECTED: 123123 for b[7]\n";
  cout << "ACTUAL: " << b[7] << endl;
  assert(12356 == b[6]);
  assert(123123 == b[7]);
  assert(999 != b[0]); // checks lower end of range

  // const object copy test
  assert(a.capacity() == b.capacity());
  for (int i = 0; i < 160; i++)
    assert(a[i] == b[i]);

  // object assignment test
  DynamicArray<int> c; c = a;
  assert(a.capacity() == c.capacity());
  for (int i = 0; i < 160; i++)
    assert(a[i] == c[i]);

  // testing string
  cout << "\nTesting type: string DynamicArray";
  DynamicArray<string> s;

   // testing DynamicArray::capacity and default constructor
  cout << "\nTesting DynamicArray::capacity and ";
  cout << "default constructor \n";
  cout << "EXPECTED: 2\n";
  cout << "ACTUAL: " << s.capacity() << endl;
  assert(2 == s.capacity());

  DynamicArray<int> test1(100);
  // testing DynamicArray :: capacity and main constructor
  cout << "Testing DynamicArray::capacity and ";
  cout << "main constructor \n";
  cout << "EXPECTED: 100\n";
  cout << "ACTUAL: " <<test1.capacity() << endl;

  // testing DynamicArray :: capacity setter-----Lower
  test1.capacity(50);
  cout << "Testing DynamicArray::capacity setter ";
  cout << "---------Lower \n";
  cout << "EXPECTED: 50\n";
  cout << "ACTUAL: "<<test1.capacity() << endl;
  assert(50 == test1.capacity());
  assert(200 != test1.capacity());
  assert(400 != test1.capacity());

  // testing DynamicArray :: capacity setter-----Higher
  test1.capacity(200);
  cout << "Now testing DynamicArray::capacity setter ";
  cout << "---------Higher \n";
  cout << "EXPECTED: 200\n";
  cout << "ACTUAL: "<<test1.capacity() << endl;
  assert(200 == test1.capacity());
  assert(50 != test1.capacity());
  assert(400!= test1.capacity());

  // testing the StaticArray<V, CAP>::operator[ ] setter
  s[6] = "computer";
  assert(12 == s.capacity());
  s[7] = "science";
  assert(12 == s.capacity());
  cout << "\nTesting StaticArray<V, CAP>::operator[ ] setter\n";
  cout << "EXPECTED: computer for s[6]\n";
  cout << "ACTUAL: " << s[6] << endl;
  assert("computer" == s[6]);
  cout << "EXPECTED: science for s[7]\n";
  cout << "ACTUAL: " << s[7] << endl;
  assert("science" == s[7]);
  s[-1000] = "data";
  assert("computer" == s[6]);
  assert("science" == s[7]);
  assert("data" != s[0]); // checks lower end of range

  //testing the DynamicArray::copy constructor
  cout << "nTesting DynamicArray::copy constructor\n";
  s[14]= "Diablo";
  s[80]= "Valley";
  const DynamicArray<string>st = s;
  cout << "EXPECTED: Capacity of  = 160\n";
  cout << "AUTUAL : "<< st.capacity() <<endl;
  cout << "EXPECTED: Diablo FOR st[14]\n";
  cout << "AUTUAL : "<< st[14] <<endl;
  assert("Diablo" == st[14]);
  assert("UC" != st[14]);
  assert("Valley" != st[14]);
  cout << "EXPECTED: Valley FOR st[80]\n";
  cout << "ACUTUAL : "<< s[80] <<endl;
  assert("Valley" == st[80]);
  assert("UC" != st[80]);
  assert("Diablo" != st[80]);

  // testing the StaticArray<V, CAP>::operator[ ] getter
  cout << "\nTesting StaticArray<V, CAP>::operator[ ] getter\n";
  cout << "EXPECTED: computer for st[6]\n";
  cout << "ACTUAL: " << st[6] << endl;
  assert("computer" == st[6]);
  cout << "EXPECTED: science for st[7]\n";
  cout << "ACTUAL: " << st[7] << endl;
  assert("computer" == st[6]);
  assert("science" == st[7]);
  assert("data" != st[0]); // checks lower end of range

  // const object copy test
  assert(s.capacity() == st.capacity());
  for (int j = 0; j < 100; j++)
    assert(s[j] == st[j]);

  // object assignment test
  DynamicArray<string> str; str = s;
  assert(s.capacity() == str.capacity());
  for (int j = 0; j < 100; j++)
    assert(s[j] == str[j]);

  cin.get();

  return 0;
}


