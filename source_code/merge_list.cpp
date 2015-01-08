/* 
* @Author: Beinan
* @Date:   2014-12-28 14:19:48
* @Last Modified by:   Beinan
* @Last Modified time: 2014-12-28 15:38:00
*/

#include <iostream>

struct node{
  int payload;
  node* next;
  node(int payload) {this->payload = payload; next = nullptr;};
};

class linkedlist{
  node *head, *tail;
public:
  //constructor, initialize head and tail to nullptr
  linkedlist() : head(nullptr),tail(nullptr){};
  //push a new node at the end of the list
  void push_back(int value){
    if(empty()){ 
      head = tail = new node(value);
    }else{      
      tail->next = new node(value);
      tail = tail->next;
    }
  }
  //return the value stored in the first node
  int front(){
    if(empty()){
      throw "The list is empty.";
    }
    return head->payload;
  }
  //remove the first node
  void pop_front(){
    if(empty()){
      throw "The list is empty.";
    }
    node* first_node = head;
    head = head->next;
    delete first_node; 
  }
  bool empty(){
    return head == nullptr;
  }
  void output(){
    node* iterator = head;
    while(iterator){
      std::cout << iterator->payload << " ";
      iterator = iterator->next;
    }
    std::cout << std::endl;
  }
  
};

//merge two sorted linked list, return a new list
linkedlist merge(linkedlist a, linkedlist b){
  linkedlist result;
  while(!a.empty() || !b.empty()){
    if(a.empty()){
      result.push_back(b.front());
      b.pop_front();
    }else if(b.empty()){
      result.push_back(a.front());
      a.pop_front();
    }else if(a.front() > b.front()){
      result.push_back(b.front());
      b.pop_front();
    }else{
      result.push_back(a.front());
      a.pop_front();
    }
  }
  return result;
}
int main(){

  linkedlist a,b;
  
  linkedlist result = merge(a, b);
  result.output();
  return 0;
}