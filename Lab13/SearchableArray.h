//Programmer: Yang Li
//Programmer's ID: 1494803
#ifndef SearchableArray_h
#define SearchableArray_h

#include <algorithm>
using namespace std;

template<typename V>
class SearchableArray
{
  V* values;
  int cap;
  V dummy;

  public:
  SearchableArray(int = 2);
  int capacity() const {return cap;}
  void capacity(int);
  V operator[](int) const;
  V& operator[](int);

  void sort(int); // sort setter function
  int bsearch(int, const V&) const;  //search getter function

  SearchableArray(const SearchableArray<V>&);
  SearchableArray<V>& operator= (const SearchableArray<V>&);
  ~SearchableArray(){delete[]values;}
};

template<typename V>
SearchableArray<V>::SearchableArray(int c)
{
  cap = c;
  values = new V[cap];
}

template<typename V>
SearchableArray<V>& SearchableArray<V>::operator=(const SearchableArray<V>& original)
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
SearchableArray<V>::SearchableArray(const SearchableArray<V>& original)
{
  cap = original.cap;
  values = new V[cap];
  for (int i = 0; i < cap; i++)
    values[i] = original.values[i];
}

template <typename V>
void SearchableArray<V>::capacity(int cap)
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
V SearchableArray<V>::operator[](int index)const
{
  if (index < 0||index >= cap) return dummy;
  return values[index];
}

template <typename V>
V& SearchableArray<V>::operator[](int index)
{
  if (index < 0) return dummy;
  if (index >= cap) capacity(2 * index);
  return values[index];
}

template <typename V>
void SearchableArray<V>::sort(int end)
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
  delete [] temp;
}

template <typename V>
int SearchableArray<V>::bsearch(int range, const V& input)const
{
  int first = 0;
  int end = range;
  int middle = 0;
  while(middle != range)
  {
    middle = (first + end - 1) /2;
    if(input == values[middle])break;
    else if(end - 1 <= first)
      middle = range;
    else if(input < values[middle])
      end = middle;
    else if(values[middle] < input)
      first = middle + 1;
  }
  if (middle == range)
    return -1;
  return middle;
}

#endif //SearchableArray_h
