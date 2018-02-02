//Programmer : Yang Li
//Programmer's ID: 1494803
#ifndef HASHTABLE_H_INCLUDED
#define HASHTABLE_H_INCLUDED

#include <algorithm>
#include <list>
#include <queue>

template <typename K, typename V, int CAP >
class HashTable
{
  struct Node
  {
    K key;
    V value;
  };

  list<Node> data[CAP];
  int(*hashCode)(const K&);//alias for has code function
  int siz;

public:
  HashTable(int(*)(const K&)=0);//constructor
  V operator[](const K&) const;//getter
  V& operator[](const K&);//setter
  bool containsKey(const K&) const;//containsKey function
  void deleteKey(const K&);//deleteKey function
  queue<K> keys() const; //keys function
  int size() const {return siz; } //size function
  void clear();//clear function
  double loadFactor() const {return 1.0 *siz / CAP;}
  //no dynamic arrangement functions
 };

//constructor
template <typename K, typename V, int CAP>
HashTable<K,V, CAP>::HashTable(int(*hashCode)(const K&))
{
  siz = 0;
  this->hashCode = hashCode;
}

//getter
template <typename K, typename V, int CAP>
V HashTable<K, V, CAP>::operator[](const K &key) const
{
  V dummy;
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;

  typename list<Node>::const_iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
   if (it->key == key)
    return it->value;
  return dummy;
}

//setter
template <typename K, typename V, int CAP>
V& HashTable<K, V, CAP>::operator[](const K &key)
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
    if (it->key == key)
      break;
  if (it == data[index].end())
  {
    Node temp;
    temp.key = key;
    data[index].push_back(temp);
    siz++;
    return data[index].back().value;
  }
  else
    return it->value;
}

//containsKey function
template <typename K, typename V, int CAP>
bool HashTable<K, V, CAP>::containsKey(const K &key) const
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;
  typename list<Node>::const_iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
    if (it->key == key)
      break;
  if (it == data[index].end())
    return false;
  else
    return true;
}

//deleteKey function
template <typename K, typename V, int CAP>
void HashTable<K, V, CAP>::deleteKey(const K &key)
{
  int index = hashCode(key) % CAP;
  if (index < 0) index += CAP;

  typename list<Node>::iterator it;
  for (it = data[index].begin(); it != data[index].end(); it++)
    if (it->key == key)
     break;

  if (it == data[index].end())
    return;
  else
  {
    data[index].erase(it);
    siz--;
  }
  return;
}

//keys function
template <typename K, typename V, int CAP>
queue<K> HashTable<K, V, CAP>::keys() const
{
  typename list<Node>::const_iterator it;
  queue<K> a;
  for (int index = 0; index < CAP; index++)
    for (it = data[index].begin(); it != data[index].end(); it++)
      a.push(it->key);
  return a;
}

//clear function
template <typename K, typename V, int CAP>
void HashTable<K, V, CAP>::clear()
{
  for (int i = 0; i < CAP; i++)
    data[i].clear();
  siz = 0;
}

#endif // HASHTABLE_H_INCLUDED
