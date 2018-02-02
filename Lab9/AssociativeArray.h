//Programmer : Yang Li
//Programmer's ID: 1494803
#ifndef AssociativeArray_h
#define AssociativeArray_h

#include <queue>
using namespace std;

template <typename K, typename V>
class AssociativeArray
{
  struct Node
  {
    K key;
    V value;
    Node* next;
  };

  Node* firstNode;
  int siz;
  V dummy;

  public:
  AssociativeArray(); //Main Constructor
  V operator[](const K&) const;//The Square Bracket Operator Getter
  V& operator[](const K&); //The Square Bracket Operator Setter
  bool containsKey(const K&) const;
  void deleteKey(const K&);
  int size() const{return siz;}; //size function prototype
  queue<K> keys() const;//keys function prototype
  void clear();//clear function prototype

  //Dynamic arrangement functions
  AssociativeArray(const AssociativeArray<K, V>&); //copy constructor prototype
  AssociativeArray<K, V>& operator=(const AssociativeArray<K, V>&);// assignment operator prototype
  ~AssociativeArray();//destructor prototype
};

//Main Constructor
template <typename K, typename V>
AssociativeArray<K, V>::AssociativeArray()
{
  firstNode = NULL;
  siz = 0;
}

//The Square Bracket Operator Getter
template <typename K, typename V>
V AssociativeArray<K, V>::operator[](const K& key) const
{
  for (Node* p = firstNode; p; p = p->next)
    if (p->key == key) return p->value;
  return dummy;
}

//The Square Bracket Operator Setter
template <typename K, typename V>
V& AssociativeArray<K, V>::operator[](const K& key)
{
  for (Node* p = firstNode; p; p = p->next)
    if (p->key == key) return p->value;
  ++siz;
  Node* temp = new Node;
  temp->key = key;
  temp->next = firstNode;
  firstNode = temp;
  return firstNode->value;
}

//containsKey Getter
template <typename K, typename V>
bool AssociativeArray<K, V>::containsKey(const K& key) const
{
  for (Node* p = firstNode; p; p = p->next)
    if (p->key == key) return true;
  return false;
}

//deleteKey Setter
template <typename K, typename V>
void AssociativeArray<K, V>::deleteKey(const K& key)
{
  Node* p, *prev;
  for (p = firstNode, prev = NULL; p; prev = p, p = p->next)
    if (p->key == key) break;

  if (p)
  {
    --siz;
    if (prev) prev->next = p->next;
    else firstNode = p->next;
    delete p;
  }
}

//The keys getter
template <typename K, typename V>
queue<K> AssociativeArray<K, V>::keys() const
{
  queue<K> result;
  for (Node* p = firstNode; p; p = p->next)
    result.push(p->key);
  return result;
}

//clear function
template <typename K, typename V>
void AssociativeArray<K, V>::clear()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
    siz--;
  }
}

//copy constructor
template <typename K, typename V>
AssociativeArray<K, V>::AssociativeArray(const AssociativeArray<K, V>& original)
{
  firstNode = NULL;
  Node* lastNode = NULL;
  siz = original.siz;
  for (Node* p = original.firstNode; p; p = p->next)
  {
    Node* temp = new Node;
    temp->value = p->value;
    temp->next = NULL;
    if (lastNode) lastNode->next = temp;
    else firstNode = temp;
    lastNode = temp;
  }
}

//assignment operator function
template <typename K, typename V>
AssociativeArray<K, V>& AssociativeArray<K, V>::operator=(const AssociativeArray<K, V>& original)
{
  if (this != &original)
  {
    while (firstNode)
    {
      Node* p = firstNode->next;
      delete firstNode;
      firstNode = p;
    }

    Node* lastNode = NULL;
    for (Node* p = original.firstNode; p; p = p->next)
    {
      Node* temp = new Node;
      temp->value = p->value;
      temp->next = NULL;
      if (lastNode) lastNode->next = temp;
      else firstNode = temp;
      lastNode = temp;
    }
    siz = original.siz;
  }
  return *this;
}

//Destructor
template <typename K, typename V>
AssociativeArray<K, V>::~AssociativeArray()
{
  while (firstNode)
  {
    Node* p = firstNode;
    firstNode = firstNode->next;
    delete p;
  }
}

#endif
