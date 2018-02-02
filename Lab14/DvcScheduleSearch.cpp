//Programmer : Yang Li
//Programmer's ID: 1494803
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;

#include <cstring> // for strtok and strcpy
#include <cstdlib>

int main()
{
  // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << endl;

  char* token;
  char buf[1000];
  const char* const tab = "\t";
  map<string ,int>subjectCodes;

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

    string term_data(term.begin(), term.begin()+2);
    string year_data(term.begin() + term.find('0') + 1, term.end());

    int year = atoi(year_data.c_str()) * 10;

    int termNums;
    if(term_data == "Sp")
      termNums = 1;
    else if(term_data == "Su")
      termNums = 2;
    else if(term_data == "Fa")
      termNums = 3;
    else continue;
    termNums = termNums + year;

    if (0 < subjectCodes.count(course) && termNums < subjectCodes[course])
      continue;
    else
      subjectCodes[course] = termNums;
  }
  fin.close();

  cout << "Enter the name of the course you would like to search for: " << endl;
  cout << "Enter Course name and Subject Code for the DVC course or enter X to exit" << endl;

  while(true)
  {
    string user_input;
    cout << "Course: ";
    getline(cin,user_input);

    if(user_input == "X" || user_input == "x")
    {
      cout << "Exiting program...Bye£¡" << endl;
      break;
    }

    if(0 < subjectCodes.count(user_input))
    {
      int year = subjectCodes[user_input] / 10;
      const int term_data = subjectCodes[user_input] % 10;
      string search_term;
      if(term_data == 1)
        search_term = "Spring";
      else if(term_data == 2)
        search_term = "Summer";
      else if(term_data == 3)
        search_term = "Fall";
      else
        continue;
      year = year + 2000;
      cout << user_input << " was last offered in " <<search_term << " " << year <<endl;
    }
    else
      cout << user_input << " could not be found as far back as the year 2000" <<endl;
  }
}
