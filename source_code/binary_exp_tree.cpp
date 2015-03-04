/* 
* @Author: Beinan
* @Date:   2015-01-17 23:03:29
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-18 17:08:16
*/

#include <iostream>
#include <stack>
#include <limits>
using namespace std;

struct treenode{
  char payload;
  treenode* left;
  treenode* right;
  treenode(int value) : payload(value), left(nullptr), right(nullptr) {}
};


class BET{
  treenode *root;
public:
  BET() : root(nullptr) {}
  void parse(const char exp[]) {
    const char* p = exp;
    stack<treenode*> s;
    while(*p != '\0'){
      if(*p >='0' && *p <='9'){
        s.push(new treenode(*p));
      }else{
        treenode* new_node = new treenode(*p);
        new_node->right = s.top();
        s.pop();
        new_node->left = s.top();
        s.pop();
        s.push(new_node);
      }
      p++;
    }
    if(s.size() != 1){
      cout << "Illegal Expression:";
      root = nullptr;
    }
    else
      root = s.top();
  }

  int evaluate() {
    if(root == nullptr)
      return std::numeric_limits<int>::max();
    return evaluate(root);
  }
private:
  int evaluate(treenode* node){
    switch(node->payload){
      case '-': return evaluate(node->left) - evaluate(node->right);      
      case '+': return evaluate(node->left) + evaluate(node->right);
      case '*': return evaluate(node->left) * evaluate(node->right);
      default: return node->payload - '0'; 
    }
  }
};
int main(){
    BET bet;
    bet.parse("752+*");
    cout << bet.evaluate() << endl;
    bet.parse("753+*753+*+");
    cout << bet.evaluate() << endl;
    bet.parse("7");
    cout << bet.evaluate() << endl;
    bet.parse("77+88+");
    cout << bet.evaluate() << endl;
    
    return 0;
}