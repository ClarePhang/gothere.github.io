/* 
* @Author: Beinan
* @Date:   2015-01-08 20:51:03
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-17 22:10:41
*/

#include <iostream>
#include "stack.h"
#include "queue.h"

struct treenode{
  int payload;
  treenode* left;
  treenode* right;
  treenode(int value) : payload(value), left(nullptr), right(nullptr) {}
};

void pre_order(treenode* root){

  stack<treenode*> s;
  treenode* current_node = root;    
  while(current_node){
    std::cout << current_node->payload << " "; //travel this node
    if(current_node->right) s.push(current_node->right);
    if(current_node->left) 
      current_node = current_node->left;
    else{
      if(s.empty())
        current_node = nullptr;
      else{
        current_node = s.top();
        s.pop();
      }
    }        
  
  }
}

void level_order(treenode* root){
  queue<treenode*> q(20);
  q.push(root);
  while(!q.empty()){
    treenode* current_node = q.top();
    q.pop();    
    std::cout << current_node->payload << " "; 
    if(current_node->left){      
      q.push(current_node->left);
    }
    if(current_node->right){
      q.push(current_node->right);              
    }
    
  }
}

int main(){
    treenode* root = new treenode(5);
    root->left = new treenode(3);
    root->right = new treenode(7);
    root->left->right = new treenode(4);

    pre_order(root);

    std::cout << "level order" << std::endl;
    level_order(root);
    return 0;
}