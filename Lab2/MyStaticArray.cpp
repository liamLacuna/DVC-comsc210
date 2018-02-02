// Programmer: Yang Li
// Programmer's ID: 1494803
#include<iostream>
#include<string>
using namespace std;

#include<cstdlib>

#include "StaticArray.h"
#include "StaticArray.h"//ifndef test

void display(const StaticArray<double, 100>&, const StaticArray<bool,100>&, int);

int main()
{
  StaticArray<double, 100> index;
  StaticArray<bool, 100> index2;
  int numbers =0;
  string buf1;
  string buf2;
  string buf3;
  int a=0;
  double b=0;

  // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << endl;

  for(int x=0; x<index.capacity(); x++)
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

    index[a] = b;
    index2[a] = true;
  }

  for(int x=0; x<index.capacity(); x++)
  {
    if(index2[x]==true)
      numbers++;
  }

  cout<<"You stored this many values : "<<numbers<<endl;

  for(int x=0; x<index.capacity(); x++)
  {
    if(index2[x]==true)
      cout<<"The index-value pairs are : "<<x<<"\t\t"<<index[x]<<endl;//show the index and values
  }

  while(true)
  {
    int position=0;
    cout<<"Input an index for me to look up[Q to quit]: ";
    cin>>buf3;
    position=atoi(buf3.c_str());
    if(buf3=="q"||buf3=="Q")
      break;
    position=atoi(buf3.c_str());
    display(index, index2, position);//using a function to display
  }

  return 0;
}

void display(const StaticArray<double, 100>& index, const StaticArray<bool, 100>& index2, int pos)
{
  if (index2[pos] && pos >= 0 && pos < index.capacity())
    cout<<"Found it---the index stored at "<<pos<< " is "<<index[pos]<<endl;
  else
    cout<<"I didn't find it "<<endl;
}
