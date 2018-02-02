//Programmer : Yang Li
//Programmer's ID: 1494803
#ifndef DynamicArray_h
#define DynamicArray_h

#include<algorithm>

template<typename V>
class DynamicArray
{
  V* values;
  int cap;
  V dummy;

  public:
  DynamicArray(int = 2);
  int capacity() const {return cap;}
  DynamicArray(const DynamicArray<V>&);
  DynamicArray<V>& operator= (const DynamicArray<V>&);
  void capacity(int);
  V operator[](int) const;
  V& operator[](int);
  ~DynamicArray(){delete[]values;}
};

template<typename V>
DynamicArray<V>::DynamicArray(int c)
{
  cap = c;
  values = new V[cap];
}

template<typename V>
DynamicArray<V>& DynamicArray<V>::operator=(const DynamicArray<V>& original)
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
DynamicArray<V>::DynamicArray(const DynamicArray<V>& original)
{
  cap = original.cap;
  values = new V[cap];
  for (int i = 0; i < cap; i++)
    values[i] = original.values[i];
}

template <typename V>
void DynamicArray<V>::capacity(int cap)
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
V DynamicArray<V>::operator[](int index)const
{
  if (index < 0||index >= cap) return dummy;
  return values[index];
}

template <typename V>
V& DynamicArray<V>::operator[](int index)
{
  if (index < 0) return dummy;
  if (index >= cap) capacity(2 * index);
  return values[index];
}


#endif //DynamicArray_h
