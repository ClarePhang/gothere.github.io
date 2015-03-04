/* 
* @Author: Beinan
* @Date:   2015-01-18 21:27:14
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-18 21:33:59
*/

#include <iostream>
#include "binary_heap.h"

using namespace std;

void print_top_k(int a[], int n, int k){
  min_binary_heap<int> heap;
  for(int i = 0; i < n ; i++){
    cout << "value " << a[i] << " is comming." << endl;
    if(heap.size() < k)
      heap.insert(a[i]);
    else if(a[i] > heap.root()){
      heap.delete_root();
      heap.insert(a[i]);
    }
  }
  cout << "final result:";
  heap.dump();
}
int main(){
    int a[] = { 3, 4, 2, 1, 7, 5, 8, 9, 0, 6};
    print_top_k(a, 10, 4);
    
    return 0;
}