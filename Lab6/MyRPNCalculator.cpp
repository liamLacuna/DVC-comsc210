//Programmer : Yang Li
//Programmer's ID: 1494803
#include<iostream>
using namespace std;

#include<cstdlib>

#include "Stack.h"

int main()
{
  Stack<double> index1;
  Stack<double> index2;
  char buf[0];
  double num1 = 0;
  double num2 = 0;

  // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << endl;

  cout << "Welcome to use the RPN calculator"<<endl;
  cout << "Please enter number and operatons or [q or Q] to quit"<<endl;

  while(true)
  {
    cout << "Enter: "<<endl;
	  if (!index1.empty())
	  {
      index2 = index1;
	    while (!index2.empty())
	    {
	      cout << index2.peek() << " ";
		    index2.pop();
	    }
	  }
	  cin >> buf;
	  if (buf[0] == 'Q' || buf[0] == 'q') break;
	  else if(buf[0]== '+')
    {
      if (index1.size() < 2) continue;
      num2 = index1.peek();
      index1.pop();
      num1 = index1.peek();
      index1.pop();
      num1 = num1 + num2;
      index1.push(num1);
    }
    else if(buf[0]== '-')
    {
      if (index1.size() < 2) continue;
      num2 = index1.peek();
      index1.pop();
      num1 = index1.peek();
      index1.pop();
      num1 = num1 - num2;
      index1.push(num1);
    }
    else if(buf[0]== '*')
    {
      if (index1.size() < 2) continue;
      num2 = index1.peek();
      index1.pop();
      num1 = index1.peek();
      index1.pop();
      num1 = num1 * num2;
      index1.push(num1);
    }
    else if(buf[0]== '/')
    {
      if (index1.size() < 2) continue;
      num2 = index1.peek();
      index1.pop();
      num1 = index1.peek();
      index1.pop();
      num1 = num1 / num2;
      index1.push(num1);
    }
    else
    {
      num1 = atof(buf);
      index1.push(num1);
    }
  }

  return 0;
}
