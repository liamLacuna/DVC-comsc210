//Programmer : Yang Li
//Programmer's ID: 1494803
#ifndef PRIORITYQUEUE_H_INCLUDED
#define PRIORITYQUEUE_H_INCLUDED

#include <algorithm>

template <typename V>
class PriorityQueue
{
  V* values;
  int siz;
  int cap;
  void capacity(int) ;

public:
  PriorityQueue(int = 2);
  void push(const V&);
  V& top() const {return values[0];}
  int size() const {return siz;}
  bool empty() const {return siz == 0;}
  void pop();
  void clear(){siz = 0;}

  //Dynamic Management Function
  PriorityQueue(const PriorityQueue<V>&);
  PriorityQueue<V>& operator=(const PriorityQueue<V>&);
  ~PriorityQueue(){delete[] values;}

};

//private capacity function
template <typename V>
void PriorityQueue<V>::capacity(int cap)
{
  V* temp = new V[cap];
  int limit = min(cap, this->cap);

  for (int i = 0; i < limit; i++)
    temp[i] = values[i];

  delete [ ] values;
  values = temp;
  this->cap = cap;
}

//constructor
template <typename V>
PriorityQueue<V>::PriorityQueue(int cap)
{
  siz = 0;
  this -> cap = cap;
  values = new V[this -> cap];
}

//push function
template <typename V>
void PriorityQueue<V>::push(const V& v)
{
  if(siz == cap) capacity(2 * cap);
  values[siz] = v;
  int index = siz;
  while(true)
  {
    int parent = (index + 1)/2 - 1;
    if(parent < 0 || values[index] < values[parent]) break;

    V temp = values[index];
    values[index] = values[parent];
    values[parent] = temp;
    index = parent;
  }
  siz++;
}

//pop function(Filling The Hole version)
template <typename V>
void PriorityQueue<V>::pop()
{
  if (siz <= 0)
    return;

  int index = 0;

  while (true)
  {
    int leftSide = index*2+1;
    int rightSide = index*2+2;

    if (leftSide >= siz)
      break;

    if (values[rightSide] < values[leftSide]||rightSide >= siz )
    {
      values[index] = values[leftSide];
      index = leftSide;
    }
    else
    {
      values[index] = values[rightSide];
      index = rightSide;
    }
  }
  siz--;
  values[index] = values[siz];

  while (true)
  {
    int parent = ((index+1)/2)-1;
    if (parent < 0 || values[index] < values[parent])
      break;

    V temp = values[index];
    values[index] = values[parent];
    values[parent] = temp;
    index = parent;
  }
}

//Dynamic management functions
template <typename V>
PriorityQueue<V>::PriorityQueue(const PriorityQueue<V>& original)
{
  cap=original.cap;
  siz=original.siz;
  values=new V[cap];
  for(int i=0; i< cap; i++)
    values[i]=original.values[i];
}

template <typename V>
PriorityQueue<V>& PriorityQueue<V>::operator=(const PriorityQueue<V>& original)
{
  if (this != &original)
  {
    delete [ ] values;
    cap = original.cap;
    siz = original.siz;
    values = new V[cap];
    for (int i = 0; i < cap; i++)
      values[i] = original.values[i];
  }
  return *this;
}

#endif // PRIORITYQUEUE_H_INCLUDED
