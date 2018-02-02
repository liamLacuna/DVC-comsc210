//Programmer : Yang Li
//Programmer's ID: 1494803
#include <iostream> // for cout, ios, and endl
#include <string> // for string
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <cstdlib> // for srand and rand
#include <ctime> // for clock(), clock_t, time, and CLOCKS_PER_SEC

#include "PriorityQueue.h"

int main()
{
  srand(time(0)); rand();

  // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << endl;

  // programmer customization go here
  int n = 5000000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  const int reps = n / 100; // one percent of starting n

  cout.setf(ios::fixed);
  cout.precision(4);
  double elapsedSecondsNorm = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    PriorityQueue<int> testPush;

    for(int index = 0; index < n; index++)
      testPush.push(rand());

    // assert that n is the size of the data structure if applicable
    assert(testPush.size() == n); // or something like that...

    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    for (int rep = 0; rep < reps; rep++)
    {
      testPush.push(rand()% 10000);
    }
    clock_t endTime = clock();

    // validation block -- assure that process worked if applicable
    while (!testPush.empty())
    {
      int topNumber = testPush.top();
      testPush.pop();
      assert(topNumber >= testPush.top());
    }

    // compute timing results
    double elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    double factor = pow(2.0, double(cycle));
    if (cycle == 0) elapsedSecondsNorm = elapsedSeconds;
    double expectedSecondsLog = log(double(n)) / log(n / factor) * elapsedSecondsNorm;

    // reporting block
    cout << elapsedSeconds;
    if (cycle == 0) cout << " (expected)";
    else cout << " (expected " << elapsedSecondsNorm << " to " << expectedSecondsLog << ')';
    cout << " for n=" << n << endl;
  }
}
