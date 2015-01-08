/* 
* @Author: Beinan
* @Date:   2014-12-28 12:38:26
* @Last Modified by:   Beinan
* @Last Modified time: 2014-12-28 13:19:32
*/
#include <iostream>

struct node{
  int payload;
  node* next;
  node(int payload) {this->payload = payload;};
};

class joseph_circle{
  node* tail;
  node* eliminate_ptr;
public:
  joseph_circle() { tail = nullptr; }
  //add a new node to joseph circle
  void add(int value){
    if(tail == nullptr){ //if the joseph circle is empty, modify tail.
      tail = new node(value);
      tail->next = tail;
    }else{ //insert new node as the tail of the circle
      node* new_node = new node(value);
      new_node->next = tail->next;
      tail->next = new_node;
      tail = new_node;
    }
  }

  void eliminate(int step) {
    node* p = tail;
    while(p != nullptr && p->next != p){ 
      //while more than one element in the circle
      for(int i = 0; i < step - 1; i++){
        p = p->next; //go forward
      }
      node* eliminated_node = p->next; //eliminate the next one
      p->next = p->next->next;
      if(eliminated_node == tail)
        tail = p; //update tail
      std::cout << "deleting:" << eliminated_node->payload << std::endl;
      delete eliminated_node;
      output();
    }
    
  }
  void output(){
    node* p = tail;
    while(p != nullptr){
      p = p -> next;
      std::cout << p->payload << " ";      
      if(p == tail)
        break;  //reach the last element of the circle
    }
    std::cout << std::endl;
  }
};
int main(){

  joseph_circle circle;
  //insert 6 nodes
  for( int i = 0; i < 6 ; i++ ){    
    circle.add(i);
  }
  circle.eliminate(3); //eliminate using a step of 3
  return 0;
}