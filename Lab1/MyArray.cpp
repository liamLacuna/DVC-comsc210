// Programmer: Yang Li
// Programmer's ID: 1494803
#include<iostream>
#include<string>
using namespace std;

#include<cstdlib>

class Array
{
  int values[100];
  int dummy;

public:
  int capacity() const {return 100;}
  int operator[ ](int) const;
  int& operator[ ](int);
};

void display(const Array&, const Array&, int);

int main()
{
  Array index;
  Array index2;
  int position;
  int numbers =0;
  char buf1[100];
  char buf2[100];
  string buf3;

 // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << endl;

  for(int x=0; x<index2.capacity(); x++)
  {
    index2[x]=0;
  }

  while(true)//Ask user to input index and value
  {
    cout<<"Input an index and a value[Q to quit]";
    cin>>buf1;
    if(buf1[0]=='q'||buf1[0]=='Q')
      break;
    cin>>buf2;
    if(buf2[0]=='q'||buf2[0]=='Q')
      break;
    index[atoi(buf1)]=atoi(buf2);
    index2[atoi(buf1)]=1;//make every stored number counts
  }

  for(int x=0; x<index2.capacity(); x++)
  {
    if(index2[x]==1)
      numbers++;
  }

  cout<<"You stored this many values : "<<numbers<<endl;

  for(int x=0; x<index.capacity(); x++)
  {
    if(index2[x]==1)
      cout<<"The index-value pairs are : "<<x<<"\t\t"<<index[x]<<endl;//show the index and values
  }

  while(true)
  {
    cout<<"Input an index for me to look up[Q to quit]: ";
    cin>>buf3;
    position=atoi(buf3.c_str());
    if(buf3=="q"||buf3=="Q")
      break;

    display(index, index2, position);//using a function to display
  }

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

void display(const Array& index, const Array& index2, int pos)
{
  if(index2[pos]==1)
    cout<<"Found it---the index stored at "<<pos<< " is "<<index[pos]<<endl;
  else
    cout<<"I didn't find it "<<endl;
}
