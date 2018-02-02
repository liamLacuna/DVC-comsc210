//Programmer: Yang Li
//Programmer's ID: 1494803
#include<iostream>
#include<string>
using namespace std;

#include<cstdlib>

#include "SearchableArray.h"

int main()
{
  SearchableArray<double> index;
  SearchableArray<bool> index2;
  int numbers =0;
  string buf1;
  string buf2;
  string buf3;
  string buf4;
  int a=0;
  double b=0;

  // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << endl;

  for(int x = 0; x < index2.capacity(); x++)
  {
    index2[x]=false;
  }

  while(true)//Ask user to input index and value
  {
    cout<<"Input an index and a value[Q to quit]";
    cin>>buf1;
    if(buf1=="q"||buf1=="Q")
      break;
    cin>>buf2;
    if(buf2=="q"||buf2=="Q")
      break;
    a=atoi(buf1.c_str());
    b=atof(buf2.c_str());

    if (a > (index.capacity() - 1))
    {
      for (int x = index.capacity(); x < (a* 2); x++)
      {
        index2[x] = false;
      }
      index[a] = b;
      index2[a] = true;
    }
    else
    {
      index[a] = b;
      index2[a] = true;
    }
  }

  for(int x=0; x<index.capacity(); x++)
  {
    if(index2[x]==true)
      numbers++;
  }

  cout<<"You stored this many values : "<<numbers<<endl;

  for(int x = 0; x < index.capacity(); x++)
  {
    if(index2[x]==true)
      cout<<"The index-value pairs are : "<<x<<"\t\t"<<index[x]<<endl;//show the index and values
  }

  //Sort
  cout << endl << "Enter the numbers of index you are going to sort :";
  cin >> buf4;
  b = atoi(buf4.c_str());
  index.sort(b);

  cout << endl;
  cout << "Sorting......Done!" <<endl;
  cout << "Now the index-value pairs are:" <<endl;

  for(int x = 0; x < index.capacity(); x++)
  {
    if(index2[x]==true)
      cout<<"   "<<x<<"\t\t"<<index[x]<<endl;
  }

  while(true)
  {
    cout<<"Input an values for me to find the index[Q to quit]: ";
    cin>>buf3;
    if(buf3=="q"||buf3=="Q") break;
    double lookUp = atof(buf3.c_str());
    if(index.bsearch(b, lookUp) < 0)
      cout << "The value " << lookUp << " was not found " <<endl;
    else
      cout << "The value " << lookUp << " was found in index " <<index.bsearch(b, lookUp) <<endl;
  }

  return 0;
}


