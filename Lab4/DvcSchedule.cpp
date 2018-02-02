//Programmer : Yang Li
//Programmer's ID: 1494803
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

#include <cstring> // for strtok and strcpy
#include <cstdlib>

#include "DynamicArray.h"

struct duplicate
{
    string term;
    string section;
};

struct subject
{
    string code;
    int counter;
};

int main()
{
  DynamicArray<duplicate>a;
  DynamicArray<subject>b;
  int count_a = 0;
  int count_b = 0;
  int count_c = 0;
  bool dupCheck = false;
  int skip = 0;

  // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << endl;

  char* token;
  char buf[1000];
  const char* const tab = "\t";

  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  // read the input file
  while (fin.good())
  {
    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue; // skip blank lines

    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line: no dash in course name
    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    cout << count_a << " Courses found..\r"; cout.flush();

    //Duplicate
    if(count_a == 0)
    {
      a[count_a].term = term;
      a[count_a].section = section;
      count_a++;
    }
    else
    for (int i = 0; i < count_a; i++)
    {
      if (term == a[i].term && section == a[i].section)// this is a duplicate
        dupCheck =  true;
    }
    if (dupCheck == true)
      {
        dupCheck = false;
        skip++;
        continue;
      }
      else
      {
        a[count_a].term = term;
        a[count_a].section = section;
        count_a++;
      }

    //Sorting
    if (count_b == 0)
    {
      b[0].code =  subjectCode ;
      b[0].counter =1 ;
      count_b ++;
    }
    else
    {
      for (int x = 0; x < count_b; x++)
        if(b[x].code == subjectCode)
        {
          b[x].counter++;
          count_c = 1;
          break;
        }
      if (count_c == 1)
        count_c = 0;
      else
      {
        b[count_b].code = subjectCode;
        b[count_b].counter = 1;
        count_b ++;
      }
    }
  }
  fin.close();

  cout <<" Duplication :             "<< skip <<endl;//display duplication

  for (int x = 0; x < count_b; x++)
    for (int y = 0; y < count_b; y++)
      if (b[x].code < b[y].code)
        swap(b[x], b[y]);

  for (int x = 0; x < count_b; x++)
  {
    cout << setw(6) << b[x].code << "   ||   " << setw(6) << b[x].counter << " sections.\n"; // display sorting
  }

  return 0;
}
