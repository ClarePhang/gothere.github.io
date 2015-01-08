/* 
* @Author: Beinan
* @Date:   2014-12-28 13:18:47
* @Last Modified by:   Beinan
* @Last Modified time: 2014-12-28 13:29:55
*/

#include <iostream>

class joseph_circle{
  int* next_persons;  //array of the indexes of next person
  int circle_length;
  int tail;
public:
  joseph_circle(int circle_length) : circle_length(circle_length){ 
    next_persons = new int[circle_length];
    for(int i = 0; i < circle_length; i++){
      next_persons[i] = (i + 1) % circle_length; //points to next person in the circle
    }
    tail = circle_length - 1; 
  }
  
  void eliminate(int step) {
    int p = tail;
    while(next_persons[p] != p){ //equivalent to p->next != p 
      //while more than one element in the circle
      for(int i = 0; i < step - 1; i++){
        p = next_persons[p]; //go forward
      }
      int eliminated_node = next_persons[p]; //eliminate the next one
      next_persons[p] = next_persons[next_persons[p]];
      if(eliminated_node == tail)
        tail = p; //update tail
      std::cout << "deleting:" << eliminated_node << std::endl;
      output();
    }
    
  }
  void output(){
    int p = tail;
    while(true){
      p = next_persons[p];
      std::cout << p << " ";      
      if(p == tail)
        break;  //reach the last element of the circle
    }
    std::cout << std::endl;
  }
};
int main(){

  joseph_circle circle(6);
  
  circle.eliminate(3); //eliminate using a step of 3
  return 0;
}