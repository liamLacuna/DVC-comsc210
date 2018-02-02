//Programmer : Yang Li
//Programmer's ID: 1494803
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Vertex
{
  string name;

  bool isVisited;
  list<int> adjacentVertices;
};

queue<int> doDepthFirstSearch(int iOriginVertex, vector<Vertex>& vertices)
{
  queue<int> searchOrder; // return this queue of indices

  // TO DO -- write this function
  stack<int> todo;

  for (int i = 0; i < vertices.size(); i++)
  {
   vertices[i].isVisited = false;
  }

  todo.push(iOriginVertex);

  while (!todo.empty())
  {
    int j = todo.top();
    todo.pop();

    if (vertices[j].isVisited == false)
    {
      vertices[j].isVisited = true;
      searchOrder.push(j);

      for (list<int>::reverse_iterator it = vertices[j].adjacentVertices.rbegin(); it != vertices[j].adjacentVertices.rend(); ++it)
      {
        if (vertices[*it].isVisited == false)
        {
          todo.push(*it);
        }
      }
    }
  }
  return searchOrder;
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
    string fromCity, toCity;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    fin.ignore(1000, 10); // skip the line with distance
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
    database[iFromVertex].adjacentVertices.push_back(iToVertex);
    database[iToVertex].adjacentVertices.push_back(iFromVertex);
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    // get the start city for the search
    string startCity;
    cout << "\nEnter the start city [blank to exit]: ";
    getline(cin, startCity);
    if (startCity.length() == 0)
    {
      cout << "Done!" <<endl;
      break;
    }

    // find the start city
    int i;
    for (i = 0; i < database.size(); i++)
      if (database[i].name == startCity)
        break;

    // DFS result
    cout << "DFS";
    queue<int> q = doDepthFirstSearch(i, database);
    while(!q.empty())
    {
      cout  << '-'<< database[q.front()].name;
      q.pop();
    }
    cout << endl;
  }
}
