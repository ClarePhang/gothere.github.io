/* 
* @Author: Beinan
* @Date:   2015-01-04 15:28:13
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-04 16:00:36
*/

#include <iostream>
#include <utility>      // std::swap

using namespace std;

//end is inclusive
void quick_sort(int a[], int begin, int end){
  if(begin >= end)
    return;
  int left = begin, right = end; 
  int pivot_value = a[left];
  
  while (left < right)
  {
    if (a[left+1] < pivot_value) { 
      a[left] = a[left+1]; 
      left++; 
    } else { 
      swap(a[left+1], a[right]); 
      right--; 
    }
  }
  a[left] = pivot_value;
  quick_sort(a, begin, left - 1);
  quick_sort(a, left + 1, end);
}
void quick_sort_wiki(int a[], int begin, int end){
  if(begin >= end)
    return;
  int pivot_index = begin; 
  int pivot_value = a[pivot_index];
  for (int k = begin + 1; k <= end; k++)
  {
    if (a[k] < pivot_value) { 
      pivot_index ++; 
      swap(a[pivot_index], a[k]);
    } 
  }
  swap(a[begin], a[pivot_index]);
  quick_sort_wiki(a, begin, pivot_index - 1);
  quick_sort_wiki(a, pivot_index + 1, end);
}
int main(){
    int a[] = { 3, 4, 2, 1, 7, 5, 8, 9, 0, 6};
    quick_sort(a, 0, 9);
    for(int i = 0; i < 10; i++)
      std::cout << a[i] << " ";
    std::cout << std::endl;
    return 0;
}