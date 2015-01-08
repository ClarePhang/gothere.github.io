/* 
* @Author: Beinan
* @Date:   2015-01-04 17:03:46
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-04 19:14:34
*/

#include <iostream>

using namespace std;

int binary_search(int a[], int key, int begin, int end){
  if(begin >= end)
    return -1;  //array is empty, not found

  int middle = (begin + end) / 2;
  if(a[middle] > key)
    return binary_search(a, key, begin, middle);
  else if(a[middle] < key)
    return binary_search(a, key, middle + 1, end);
  else
    return middle;
}

int binary_search_iterative(int a[], int key, int begin, int end){
  int middle;
  while(begin < end){
    middle = (begin + end) / 2;
    if(a[middle] > key)
      end = middle;
    else if(a[middle] < key)
      begin = middle + 1;
    else
      return middle;
  }
  return -1;  //array is empty, not found

      
}
int main(){
    int a[] = { 1, 3, 5, 7, 9};
    for(int i = 0; i < 15; i++){
      cout << "Searching " << i << endl;
      cout << " Position is " << binary_search_iterative(a, i, 0, 5) << endl;      
    }
    return 0;
}