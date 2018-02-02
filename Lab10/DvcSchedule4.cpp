//Programmer : Yang Li
//Programmer's ID: 1494803
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
using namespace std;

#include <cstring> // for strtok and strcpy
#include <cstdlib>
#include <ctime>

#include "HashTable.h"
#include "DynamicArray.h"

int hashCode(const string&);

int main()
{
  // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << endl;

  HashTable<string, HashTable<string, bool, 10000>, 20> alreadySeen(hashCode);
  HashTable<string, HashTable<string, int, 200>, 200> subjectCounts(hashCode);
  DynamicArray<string>listOfSeen;
  int nList = 0;
  int nDups = 0;
  int lineGet = 0;

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

    if (!alreadySeen.containsKey(term)) alreadySeen[term] = HashTable<string, bool, 10000>(hashCode);
    if (!subjectCounts.containsKey(subjectCode)) subjectCounts[subjectCode] = HashTable<string, int, 200>(hashCode);


    bool duplicate = false;
    //Duplicate Checking
    alreadySeen[term];//call the list of term
    if (alreadySeen[term].containsKey(section)) //when term and section both match
    {
      nDups++;
      continue;
    }
	  alreadySeen[term][section] = true;//mark it as a match

	  //Counting
	  subjectCounts[subjectCode];//call the list of subjectCode
    if (subjectCounts[subjectCode].containsKey(course))
      subjectCounts[subjectCode][course]++;//add one if the course already exist
    else
      subjectCounts[subjectCode][course] = 1;// make it one if the the course have not exist

    for (int x = 0; x < nList ; x++)
    {
      if(listOfSeen[x]==subjectCode)
      {
        duplicate = true;
        break;
      }
    }
    if(!duplicate)
    {
      duplicate = true;
    }
    else
    {
      duplicate = false;
      continue;
    }
    listOfSeen[nList] = subjectCode;
    nList++;
  }
  fin.close();

  //Sort the array
  for (int i=0;i<nList;i++)
  {
    for (int j=0;j<nList;j++)
      if(listOfSeen[j]>listOfSeen[i])
        swap(listOfSeen[i],listOfSeen[j]);
  }
  cout <<endl<<"Duplication :             "<< nDups <<endl;//display duplication

  //display the sorting
  for (int x = 0; x < nList; x++)
  {
    cout << endl << listOfSeen[x] << ", " << setw(2)<< subjectCounts[listOfSeen[x]].size() << " Course(s)" << endl;
    //copy-pop
    for (queue<string> keys = subjectCounts[listOfSeen[x]].keys(); !keys.empty(); keys.pop())
    cout << "   " << setw(12) << keys.front() << " || " << setw(2) << subjectCounts[listOfSeen[x]][keys.front()] <<setw(2) << " Section(s)" << endl;
  }

  cout.setf(ios::fixed);
  cout.precision(4);
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;//stop timer
  cout<<endl<<endl<<"Execution time:  "<<elapsedSeconds<<"  Seconds."<<endl<<endl;// display timer
}

int hashCode(const string& key)
{
  int code=0;
  for (int x=0;x<key.length();x++)
    code += key.at(x);

  return code;
}


