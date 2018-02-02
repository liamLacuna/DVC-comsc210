//Programmer : Yang Li
//Programmer's ID: 1494803
#define _CRT_SECURE_NO_WARNINGS

#include <iostream> // for cout, ios, and endl
#include <string> // for string
#include <fstream>
using namespace std;

#include <cmath> // for log and pow
#include <ctime> // for clock(), clock_t, time, and CLOCKS_PER_SEC
#include <cstring>

#include "StaticArray.h"
#include "DynamicArray.h"

struct seenForTerm
{
  string term;
  DynamicArray <string> section;
  int nSections;
};

int main()
{
  // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << endl;

  int n = 8000;
  string bigOh = "O(n)";//determine O(n)

  cout.setf(ios::fixed);
  cout.precision(4);
  double elapsedSecondsNorm = 0;
  double expectedSeconds = 0;

  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    StaticArray<seenForTerm, 200>a;
    int count_a = 0;
    int counter = 0;
    int nDups = 0;
    clock_t startTime = clock();

    ifstream fin;
    fin.open("dvc-schedule.txt");

    if (!fin.good()) throw "I/O error";
    while (fin.good()&&counter < n)
    {
      counter++;

      char* token;
      char buf[1000];
      const char* const tab = "\t";

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

      bool termMatchFlag=false;
      bool dupCheck=false;

      for (int i=0; i<count_a; i++)
      {
        if (a[i].term==term)
        {
          termMatchFlag=true; //term match
          for (int j=0;j<a[i].nSections;j++)//section match
          {
            if (a[i].section[j]==section)
            {
              dupCheck=true;
              nDups++;
              break;
            }
          }

          if (!dupCheck)//term match but section does not match
          {
            int x=a[i].nSections;
            a[i].section[x]=section;
            a[i].nSections++;
            dupCheck=true;
          }
        }
        if (dupCheck) break;//break because not need to check others
      }
    }
    fin.close();

    clock_t endTime = clock();

    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    double factor = pow(2.0, double(cycle));
    if (cycle == 0)
      elapsedSecondsNorm = elapsedSeconds;
    else if (bigOh == "O(n)")
      expectedSeconds = factor * elapsedSecondsNorm;
    else if (bigOh == "O(n log n)")
      expectedSeconds = factor * log(double(n)) / log(n / factor) * elapsedSecondsNorm;
    else if (bigOh == "O(n squared)")
      expectedSeconds = factor * factor * elapsedSecondsNorm;

    // reporting block
    cout << elapsedSeconds;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedSeconds << ')';
    cout << " for n=" << n << endl;
  }
}
