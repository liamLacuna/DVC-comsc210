//Programmer : Yang Li
//Programmer's ID: 1494803
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <time.h>
using namespace std;

#include <cstring> // for strtok and strcpy
#include <cstdlib>

#include "DynamicArray.h"

struct seenForTerm
{
  string term;
  DynamicArray <string> section;
  int nSections;
};

struct subject
{
  string code;
  int counter;
};

int main()
{
  DynamicArray<seenForTerm>a; //Duplicate check
  DynamicArray<subject>b; //SubjectCode
  int count_a = 0;
  int count_b = 0;
  int count_c = 0;
  int nDups = 0;
  int lineGet = 0;

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

  clock_t startTime = clock();//start timer

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

    //duplicate
    bool termMatchFlag = false;
    bool dupCheck = false;
    int indexForTerm = 0;
    for(int x = 0; x < count_a ; x++)
    {
      if(a[x].term == term)// term match
      {
        indexForTerm = x;
        termMatchFlag = true;
        for(int i = 0; i < a[x].nSections; i++)
          if(a[x].section[i] == section)// section also match
          {
            dupCheck = true;
            nDups++;
            break;
          }
      }
    }

    if(!dupCheck)// term match but section does not match
    {
      if(!termMatchFlag)// term and section both do not match
      {
        a[count_a].term = term;
        a[count_a].nSections = 1;
        a[count_a].section[0] = section;
        ++count_a;
      }
      else
      {
        int index2 = a[indexForTerm].nSections;
        a[indexForTerm].section[index2] = section;
        a[indexForTerm].nSections++;
      }
    }
    else
      continue;

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
    //display processing bar
    lineGet++;
    if(lineGet%1000 == 0)
    {
      cout<<'.'; cout.flush();
    }
  }
  fin.close();

  cout <<endl<<" Duplication :             "<< nDups <<endl;//display duplication

  for (int x = 0; x < count_b; x++)
    for (int y = 0; y < count_b; y++)
      if (b[x].code < b[y].code)
        swap(b[x], b[y]);

  cout << setw(6) <<" Subject ||  Section "<<endl;

  for (int x = 0; x < count_b; x++)
  {
    cout << setw(6) << b[x].code << "   ||   " << setw(6) << b[x].counter<<endl;// display sorting
  }

  cout.setf(ios::fixed);
  cout.precision(4);
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;//stop timer
  cout<<endl<<endl<<"Execution time:  "<<elapsedSeconds<<"  Seconds."<<endl<<endl;// display timer

  return 0;
}
