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

struct Terminus
{
  int prev;
  double cost;
  int vertex;

  bool operator<(const Terminus & v) const
  {
    return cost > v.cost;
  }
};

struct Vertex
{
  string name;

  bool isVisited;
  list<pair<int, double> > adjacentVertices;
  int prev;
  double cost;
};

//void printV(Vertex v, vector<Vertex>& database);

pair<stack<int>, double> getCheapestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it; // to iterate over adjacentVertices
  // TO DO -- write this function
  for (int i = 0; i < database.size(); i++)
  {
    database[i].cost = 0;
    database[i].prev = -1;
    database[i].isVisited = false;
  }

  //priority queue of Terminus objects
  priority_queue<Terminus> PQ;

  Terminus startVertex;
  startVertex.cost = 0;
  startVertex.prev = -1;
  startVertex.vertex = iStart;

  PQ.push(startVertex);

  while (!PQ.empty())
  {
    Terminus temp = PQ.top();
    PQ.pop();

    if (database[temp.vertex].isVisited == true)
      continue;

    database[temp.vertex].isVisited = true;
    database[temp.vertex].cost = temp.cost;
    database[temp.vertex].prev = temp.prev;

    if (temp.vertex == iEnd)
      break;

    //unvisited neighbors
    for (it = database[temp.vertex].adjacentVertices.begin(); it != database[temp.vertex].adjacentVertices.end(); ++it)
    {
      Terminus neighborsContainer;
      neighborsContainer.vertex = it->first;
      neighborsContainer.cost = (temp.cost + it->second);
      neighborsContainer.prev = temp.vertex;

      PQ.push(neighborsContainer);
    }
  }
  result.second = database[iEnd].cost;
  for (int vertex = iEnd; vertex >= 0; vertex = database[vertex].prev)
	{
		result.first.push(vertex);
	}
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
    int startCity = -1;
    int endCity = -1;

    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    // find the from city
    for (int i = 0; i < database.size(); i++)
      if (database[i].name == fromCity)
      {
        startCity = i;
        break;
      }


    cout << "Enter the destination city [blank to exit]: ";
    getline(cin, toCity);
    if (toCity.length() == 0) break;

    // find the to city
    for (int i = 0; i < database.size(); i++)
      if (database[i].name == toCity)
      {
        endCity = i;
        break;
      }

    // find the destination city and get cheapest route
    if (startCity >= 0 && endCity >= 0)
    {
      pair<stack<int>, double> result = getCheapestRoute(startCity, endCity, database);
      cout << "Total miles: " << result.second;
      while (!result.first.empty())
      {
        cout << "-" <<
             database[result.first.top()].name;
        result.first.pop();
      }
    }
    else
      cout << "ERROR: One or more cities not found in database..." << endl;
    cout << endl << endl;
  }
  cout << "Done!" <<endl;
}
