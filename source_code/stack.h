/* 
* @Author: Beinan
* @Date:   2015-01-08 20:51:03
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-17 18:00:41
*/

template <typename T>
struct node{
  T payload;
  node* next;
  node(T payload) {this->payload = payload;};
};

template <typename T>
class stack{
  node<T>* head;

public:
  stack() : head(nullptr) {}
  
  void push(T value){
    node<T>* new_node = new node<T>(value);
    new_node->next = head;
    head = new_node;  
  }

  void pop(){
    if(empty())
      throw "You cannot pop an element from an empty stack";
    node<T>* temp = head;
    head = head->next;
    delete temp;
  }

  T top(){
    if(empty())
      throw "You cannot get the top element from an empty stack";
    return head->payload; 
  }
  
  bool empty(){
    return head == nullptr;
  }
};