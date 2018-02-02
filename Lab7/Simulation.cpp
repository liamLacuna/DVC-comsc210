//Programmer : Yang Li
//Programmer's ID: 1494803
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cmath> //the poisson function
#include <cstdlib> //the poisson function
#include <ctime>

#include "DynamicArray.h"
#include "Queue.h"

int getRandomNumberOfArrivals(double);

struct Customer
{
  char IDtag;
  int arrivalTime;
  int serviceEndTime;
};

struct Status
{
  Customer customer;
  bool idle;
};


int main()
{
  // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << endl;

  srand(time(NULL));
  rand();

  int num;
  double rate;
  int maxL;
  int minT;
  int maxT;
  int timetotal;
  int a=0;

  // open the input file
  ifstream fin;
  fin.open("simulation.txt");
  if (!fin.good()) throw "I/O error";

  //read the input values from a text file, one per line
  if (fin.good())
  {
    string buf;
    fin >> buf;
    num = atoi(buf.c_str());
    fin >> buf;
    rate = atof(buf.c_str());
    fin >> buf;
    maxL = atoi(buf.c_str());
    fin >> buf;
    minT = atoi(buf.c_str());
    fin >> buf;
    maxT = atoi(buf.c_str());
    fin >> buf;
    timetotal = atoi(buf.c_str());
  }
  fin.close();

  cout << "number of servers    : " << num << endl;
  cout << "customer arrival rate: " << rate << " per minute, for " << timetotal << " minutes" << endl;
  cout << "maximum queue length : " << maxL << endl;
  cout << "minimum service time : " << maxT << endl;
  cout << "maximum service time : " << minT << endl << endl;


  // declare and create and assign arrays and queues to be used in the solution
  DynamicArray<Status> nowServing;
  Queue<Customer> waitQ;

  for (int x = 0; x < nowServing .capacity(); x++)
  {
    nowServing [x].idle = true;
  }

  // the clock time loop
  for (int time = 0;; time++)
  {
  	for (int x = 0; x < num; x++)
  	{
  		if (nowServing [x].idle)
  		{
  			if (nowServing[x].customer.serviceEndTime == time)
  					nowServing[x].idle = false;
  		}
  	}

    if (time < timetotal)// handle new arrivals -- can be turned away if wait queue is at maximum length!
  	{
  		int newArrivals = getRandomNumberOfArrivals(rate);
  		for (int x = 0; x < newArrivals; x++)
  		{
  			if (waitQ.size() < maxL)
  			{
  				Customer customer2;
  				customer2.arrivalTime = time;
          customer2.IDtag = (char)('A' + (a++ % 26));
          waitQ.push(customer2);
  			}
  		}
  	}

  	for (int x = 0; x < num; x++)// for idle servers, move customer from wait queue and begin service
  	{
  		if (!nowServing[x].idle && !waitQ.empty())
  		{
  		  nowServing[x].customer = waitQ.front();
        waitQ.pop();
        nowServing[x].idle = true;
        nowServing[x].customer.serviceEndTime = time + minT + rand() % (maxT - minT + 1);
  		}
  	}

  	cout << "Time: " << time << endl;//display the summary
  	cout << "---------------------------------" << endl;
  	cout << " line | now serving | wait queue " << endl;
  	cout << "------ ------------- ------------" << endl;
  	for (int x = 0; x < num; x++)
  	{
  	  cout << "   " << x;
  	  cout << "         ";
  	  if (nowServing[x].idle) cout << nowServing[x].customer.IDtag << "        ";
  	  else
  	  	cout << "         ";
  	  if (x == 0)
      {
        Queue<Customer> waitq = waitQ;
  	    while (waitq.size() != 0)
        {
          cout << waitq.front().IDtag;
  	  	  waitq.pop();
  	    }
  	  }
  	  cout<<endl;
    }

  	//Pause for the user to press ENTER
  	cout <<endl<< "---------------------------------" << endl;
    cout << "Press ENTER to continue.." << endl;
    cin.get();

    bool done = true;
  	if (time > timetotal && waitQ.empty())
  	{
  	  for (int x = 0; x < num; x++)
  	  {
  	  	if (nowServing[x].idle)
  	  	  done = false;
  	  }
  	}
  	else done = false;
  	if (done) break;
  	done = true;
  }
  cout<<"Done!"<<endl;
}

// requires cmath and cstdlib
int getRandomNumberOfArrivals(double averageArrivalRate)
{
  int arrivals = 0;
  double probOfnArrivals = exp(-averageArrivalRate);
  for (double randomValue = (double)rand() / RAND_MAX;
  (randomValue -= probOfnArrivals) > 0.0;
    probOfnArrivals *= averageArrivalRate / (double)++arrivals);
    return arrivals;
}
