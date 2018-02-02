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
#include "PriorityQueue.h"
#include "Queue.h"


int getRandomNumberOfArrivals(double);

struct Customer
{
  char IDtag;
  int arrivalTime;
  int endTime;
};

struct Status
{
  int numServer;
  int serverEndTime;
  bool operator<(const Status& right){return right.serverEndTime < serverEndTime;}
};

int main()
{
  // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << endl;

  srand(time(NULL));
  rand();

  int nServers;
  double rate = 0.0;
  int maxL = 0;
  int minT = 0;
  int maxT = 0;
  int timetotal = 0;
  int a = 0;
  int waitTime = 0;


  // open the input file
  ifstream fin;
  fin.open("simulation.txt");
  if (!fin.good()) throw "I/O error";

  //read the input values from a text file, one per line
  if (fin.good())
  {
    string buf;
    fin >> buf;
    nServers = atoi(buf.c_str());
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

  cout << "number of servers    : " << nServers << endl;
  cout << "customer arrival rate: " << rate << " per minute, for " << timetotal << " minutes" << endl;
  cout << "maximum queue length : " << maxL << endl;
  cout << "minimum service time : " << maxT << endl;
  cout << "maximum service time : " << minT << endl << endl;


  // declare and create and assign arrays and queues to be used in the solution
  DynamicArray<Customer> nowServing(nServers);
  Queue<Customer> waitQ;
  PriorityQueue<Status> eventQ;
  DynamicArray<bool> idle(nServers);

  for (int x = 0; x < nServers; x++)
  {
    idle[x] = false;
  }

  // the clock time loop
  for (int time = 0;; time++)
  {
  	while(time == eventQ.top().serverEndTime && !eventQ.empty())
    {
      int n;
      n = eventQ.top().numServer;
      idle[n] = false;
      nowServing[n].IDtag =' ';
      eventQ.pop();
    }

    if (time < timetotal)
  	{
  		int newArrivals = getRandomNumberOfArrivals(rate);
  		for (int x = 0; x < newArrivals; x++)
  		{
  			if (waitQ.size() < maxL)
  			{
  				Customer customer2;
  				customer2.arrivalTime = time;
          customer2.IDtag = (char)'A' + (a % 26);
          a++;
          waitQ.push(customer2);
  			}
  		}
  	}

  	for (int x = 0; x < nServers; x++)
  	{
  		if (idle[x] == false && !waitQ.empty())
  		{
  		  nowServing[x] = waitQ.front();
        waitQ.pop();
        idle[x] = true;
        nowServing[x].endTime = time + minT + rand() % (maxT - minT + 1);

        Status event;
        event.numServer = x;
        event.serverEndTime = time + minT + rand() % (maxT - minT + 1);
        eventQ.push(event);
  		}
  	}

  	cout << "Time: " << time << endl;//display the summary
  	cout << "-----------------------------------------------------------" << endl;
  	cout << " server | time for end-of-service | now serving | waitqueue" << endl;
  	cout << "------- + ----------------------- | ------------| ---------" << endl;

  	PriorityQueue<Status> display;
    display = eventQ;
  	for (int x = 0; x < nServers; x++)
  	{
  	  cout << "   ";
  	  cout << " " << display.top().numServer;
  	  cout << "                 " << display.top().serverEndTime;
  	  display.pop();
  	  if (idle[x])
        cout << "                 "<< nowServing[x].IDtag << "        ";
  	  else
  	  	cout << "         ";
  	  if (x == 0)
      {
        Queue<Customer> waitq = waitQ;
  	    while (waitq.size() != 0)
        {
          Customer display = waitq.front();
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
    for (int x = 0; x < nServers; x++)
    {
      if (idle[x] == true)
        done = false;
        break;
    }

    if(done&&time>=timetotal)
    {
      cout << "---------------------------------"<<endl;
      break;
    }
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

