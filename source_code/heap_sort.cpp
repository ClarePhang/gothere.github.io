/* 
* @Author: Beinan
* @Date:   2015-01-18 20:05:52
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-18 21:28:01
*/

#include <iostream>
#include "binary_heap.h"


void heap_sort(int a[], int length){
  min_binary_heap<int> heap;
  for(int i = 0; i < length; i++){
    heap.insert(a[i]);
  }
  for(int i = 0; i < length; i++){
    a[i] = heap.root();
    heap.delete_root();
  }
}
int main(){
    int a[] = { 3, 4, 2, 1, 7, 5, 8, 9, 0, 6};
    heap_sort(a, 10);
    for(int i = 0; i < 10; i++)
      std::cout << a[i] << " ";
    std::cout << std::endl;
    return 0;

}