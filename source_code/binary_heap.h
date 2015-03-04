/* 
* @Author: Beinan
* @Date:   2015-01-05 12:59:46
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-17 18:00:41
*/

#include <vector>
#include <algorithm>  //for swap
#include <iostream>

template <typename T>
class binary_heap{
  std::vector<T> data;
protected:
  virtual bool compare(T a, T b) = 0;
public:
  
  void insert(T value){
    data.push_back(value);
    int pos = data.size() - 1;
    while(pos > 0){
      int parent = (pos - 1) / 2;
      if(parent < 0 || !compare(value, data[parent])){
        break; //less than parent, 
      }
      std::swap(data[pos], data[parent]);
      pos = parent; 
    } 
    dump();
  }

  T root(){
    return data[0];
  }

  //delete the root of the heap
  void delete_root(){
    data[0] = data.back();
    data.pop_back();
    heapify(0);
    return;
  }
  
  bool empty(){
    return data.empty();
  }

  int size(){
    return data.size();
  }
  void dump(){
    for(int i = 0; i < data.size(); i++){
      std::cout << data[i] << " ";
    }
    std::cout << "\n";
  }
private:
  void heapify(int pos){
    
    dump();
    int left = 2 * pos + 1;
    int right = 2 * pos + 2;
    int largest_pos = pos;
    if(left < data.size() && compare(data[left], data[largest_pos]))
      largest_pos = left;
    if(right < data.size() && compare(data[right], data[largest_pos]))
      largest_pos = right;
    if(largest_pos != pos){
      std::swap(data[pos], data[largest_pos]);
      heapify(largest_pos);
    }
    
  }
};

template <typename T>
class max_binary_heap : public binary_heap<T>{
protected:
  virtual bool compare(T a, T b)
  {
    return a > b;
  }
};

template <typename T>
class min_binary_heap : public binary_heap<T>{
protected:
  virtual bool compare(T a, T b)
  {
    return a < b;
  }
};