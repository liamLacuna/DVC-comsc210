//Programmer : Yang Li
//Programmer's ID: 1494803
#ifndef STACK_H
#define STACK_H

template <typename V>
class Stack
{
  struct Node
  {
    V value;
    Node* next;
  };

  V dummy;
  Node* firstNode; //the head pointer
  int siz; //tracking the number of nodes

public:
  Stack();
  void push(const V&);
  V& peek();
  void pop();
  int size()const{return siz;}
  bool empty() const{return siz == 0;}
  void clear();
  Stack(const Stack<V>&);
  Stack<V>& operator= (const Stack<V>&);
  ~Stack();
};

//Main Constructor
template<typename V>
Stack<V>::Stack()
{
  firstNode = NULL;
  siz = 0;
}

//Push function
template <typename V>
void Stack<V>::push(const V& value)
{
  Node* temp = new Node;
  temp->value = value;
  temp->next = firstNode;
  firstNode = temp;
  ++siz;
}

//Peek function
template <typename V>
V& Stack<V>::peek()
{
  if(firstNode == 0)return dummy;
  return firstNode->value;
}

//Pop function
template <typename V>
void Stack<V>::pop()
{
  if (firstNode )
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
}

//Clear function
template <typename V>
void Stack<V>::clear()
{
  while(firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    --siz;
  }
}

//Copy constructor
template <typename V>
Stack<V>::Stack(const Stack<V>& original)
{
  firstNode = 0;
  Node* lastNode = 0; // temporary tail
  siz = original.siz;
  for (Node* p = original.firstNode; p; p = p->next)
  {
    Node* temp = new Node;
    temp->value = p->value;
    temp->next = 0;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }
}

//Assignment operator function
template <typename V>
Stack<V>& Stack<V>::operator=(const Stack<V>& original)
{
  if (this != &original)
  {
    // deallocate existing list
    while (firstNode)
    {
      Node* p = firstNode->next;
      delete firstNode;
      firstNode = p;
    }

    Node* lastNode = 0; // temporary tail
    for (Node* p = original.firstNode; p; p = p->next)
    {
      Node* temp = new Node;
      temp->value = p->value;
      temp->next = 0;
      if (lastNode) lastNode->next = temp;
      else firstNode = temp;
      lastNode = temp;
    }
    siz = original.siz;
  }
  return *this;
}

//Destructor function
template <typename V>
Stack<V>::~Stack()
{
  while(firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
  }
}

#endif
