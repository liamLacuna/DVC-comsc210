//Programmer : Yang Li
//Programmer's ID: 1494803
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;

#include <cstdlib>

struct Vertex
{
  string name;

  bool isVisited;
  list<pair<int, double> > adjacentVertices;
  int prev;
  double cost;
};

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it; // to iterate over adjacentVertices
  // TO DO -- write this function
  queue<int> q;

  for (int i = 0; i < database.size(); i++)
  {
    database[i].cost = 0;
    database[i].prev = -1;
    database[i].isVisited = false;
  }

  database[iStart].isVisited = true;
  q.push(iStart);

  while (!q.empty())
  {
    int temp = q.front();
    q.pop();

    for (it = database[temp].adjacentVertices.begin(); it != database[temp].adjacentVertices.end(); it++)
    {
      if (database[it->first].isVisited == false)
      {
        database[it->first].isVisited = true;
        database[it->first].cost = (database[temp].cost + 1);
        database[it->first].prev = temp;
        q.push(it->first);
      }

      if (it->first == iEnd)
      {
        while(!q.empty())
        {
          q.pop();
        }
        break;
      }
    }
  }

  result.second = database[iEnd].cost;

  for (int vertex = iEnd; vertex >= 0; vertex = database[vertex].prev)
    result.first.push(vertex);
  return result;
}

int main()
{
  // programmer's identification
  cout << "Programmer: Yang Li\n";
  cout << "Programmer's ID: 1494803\n";
  cout << "File: " << __FILE__ << endl;

  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";

  // process the input file
  vector<Vertex> database;
  while (fin.good()) // EOF loop
  {
    string fromCity, toCity, cost;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    getline(fin, cost);
    fin.ignore(1000, 10); // skip the separator

    // add vertices for new cities included in the edge
    int iToVertex = -1, iFromVertex = -1, i;
    for (i = 0; i < database.size(); i++) // seek "to" city
      if (database[i].name == fromCity)
        break;
    if (i == database.size()) // not in database yet
    {
      // store the vertex if it is new
      Vertex fromVertex;
      fromVertex.name = fromCity;
      database.push_back(fromVertex);
    }
    iFromVertex = i;

    for (i = 0; i < database.size(); i++) // seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) // not in vector yet
    {
      // store the vertex if it is new
      Vertex toVertex;
      toVertex.name = toCity;
      database.push_back(toVertex);
    }
    iToVertex = i;

    // store bi-directional edges
    double edgeCost = atof(cost.c_str());
    database[iFromVertex].adjacentVertices.push_back(pair<int, double>(iToVertex, edgeCost));
    database[iToVertex].adjacentVertices.push_back(pair<int, double>(iFromVertex, edgeCost));
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    // find the from city
    int iFrom;
    for (iFrom = 0; iFrom < database.size(); iFrom++)
      if (database[iFrom].name == fromCity)
        break;

    cout << "Enter the destination city [blank to exit]: ";
    getline(cin, toCity);
    if (toCity.length() == 0) break;

    // find the destination city
    int iTo;
    for (iTo = 0; iTo < database.size(); iTo++)
      if (database[iTo].name == toCity)
        break;

    pair<stack<int>, double> result = getShortestRoute(iFrom, iTo, database);
    cout << endl << "Total edges: " << result.second;
    cout << "";
    while (!result.first.empty())
    {
      cout << '-' << database[result.first.top()].name; result.first.pop();
    }

    cout << endl;
  }
  cout << "Done!" <<endl;
}
