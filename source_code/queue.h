/* 
* @Author: Beinan
* @Date:   2015-01-08 20:59:03
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-17 18:00:41
*/



template <typename T>
class queue{
  T* data;
  int head, tail, size, data_length;
public:
  queue(int length) : head(0), tail(0), size(0), data_length(length) {
    data = new T[length];
  }
  
  void push(T value){
    if(size == data_length)
      throw "queue is full";
    data[head] = value;
    head = (head + 1) % data_length;
    size ++;
  }

  void pop(){
    if(empty())
      throw "queue is empty";
    tail = (tail + 1) % data_length;
    size --;
  }

  T top(){
    if(empty())
      throw "You cannot get the top element from an empty queue";
    return data[tail]; 
  }
  
  bool empty(){
    return size == 0;
  }
};