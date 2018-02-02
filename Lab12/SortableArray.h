//Programmer: Yang Li
//Programmer's ID: 1494803
#ifndef SortableArray_h
#define SortableArray_h

#include <algorithm>
using namespace std;

template<typename V>
class SortableArray
{
  V* values;
  int cap;
  V dummy;

  public:
  SortableArray(int = 2);
  int capacity() const {return cap;}
  void capacity(int);
  V operator[](int) const;
  V& operator[](int);
  void sort(int); // sort setter function

  SortableArray(const SortableArray<V>&);
  SortableArray<V>& operator= (const SortableArray<V>&);
  ~SortableArray(){delete[]values;}
};

template<typename V>
SortableArray<V>::SortableArray(int c)
{
  cap = c;
  values = new V[cap];
}

template<typename V>
SortableArray<V>& SortableArray<V>::operator=(const SortableArray<V>& original)
{
  if(this != &original)
  {
    delete[]values;
    cap = original.cap;
    values = new V[cap];
    for(int i = 0; i < cap; i++)
      values[i]=original.values[i];
  }
  return *this;
}

template <typename V>
SortableArray<V>::SortableArray(const SortableArray<V>& original)
{
  cap = original.cap;
  values = new V[cap];
  for (int i = 0; i < cap; i++)
    values[i] = original.values[i];
}

template <typename V>
void SortableArray<V>::capacity(int cap)
{
  V* temp = new V[cap];
  int limit = min(cap, this->cap);
  for (int i = 0; i < limit; i++)
    temp[i] = values[i];

  delete [ ] values;
  values = temp;
  this->cap = cap;
}

template <typename V>
V SortableArray<V>::operator[](int index)const
{
  if (index < 0||index >= cap) return dummy;
  return values[index];
}

template <typename V>
V& SortableArray<V>::operator[](int index)
{
  if (index < 0) return dummy;
  if (index >= cap) capacity(2 * index);
  return values[index];
}

template <typename V>
void SortableArray<V>::sort(int end)
{
  int *temp = new int[end];
  for(int x = 1; x < end; x *= 2)
  {
    int index = 0;
    for (int i = 0; i < end; i++) temp[i] = values[i];
    for (int i = 0; i < end; i += 2 * x)
    {
      int left = i;
      int leftMax = min(left + x, end);
      int right = leftMax;
      int rightMax = min(right + x, end);
      while (true)
      {
        if (left == leftMax && right == rightMax) break;
        if (left == leftMax) values[index++] = temp[right++];
        else if (right == rightMax) values[index++] = temp[left++];
        else if (temp[right] < temp[left]) values[index++] = temp[right++];
        else values[index++] = temp[left++];
      }
    }
  }
}

#endif //SortableArray_h
