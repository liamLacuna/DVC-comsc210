// Programmer: Yang Li
// Programmer's ID: 1494803
#ifndef StaticArray_h
#define StaticArray_h

template<typename V, int CAP>
class StaticArray
{
  V value[CAP];
  V dummy;

  public:
    int capacity() const{return CAP;}
    V operator[](int) const;
    V& operator[](int);

};

template<typename V, int CAP>
V& StaticArray<V, CAP>::operator[](int index)
{
  if (index < 0) return dummy;
  if (index >= CAP) return dummy;
  return value[index];
}

template<typename V, int CAP>
V StaticArray<V, CAP>::operator[](int index)const
{
  if (index<0) return dummy;
  if (index>=CAP) return dummy;
  return value[index];
}

#endif // StaticArray_h
