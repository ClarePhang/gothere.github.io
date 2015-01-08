/* 
* @Author: Beinan
* @Date:   2014-12-28 15:51:43
* @Last Modified by:   Beinan
* @Last Modified time: 2014-12-28 16:52:47
*/

#include <iostream>

//merge two sorted sub-array
void merge(int array[], int temp[], int left, int middle, int right){
  int p_left = left, p_right = middle;
  int i = left;
  while(p_left < middle || p_right < right){
    if(p_left >= middle){
      temp[i] = array[p_right];
      p_right ++;
    } else if(p_right >= right){
      temp[i] = array[p_left];
      p_left ++;
    } else if(array[p_left] > array[p_right]){
      temp[i] = array[p_right];
      p_right ++;
    } else {
      temp[i] = array[p_left];
      p_left ++;
    }
    i++;
  }
  for(int i = left; i < right ; i++)
    array[i] = temp[i]; //copy back
}
//top down merge sort
//begin is inclusive, end is exclusive
void merge_sort_recursive(int array[], int temp[], int left, int right){
  if(right - left <= 1)
    return;
  int middle = (left + right) / 2;
  merge_sort_recursive(array, temp, left, middle);
  merge_sort_recursive(array, temp, middle, right);
  merge(array, temp, left, middle, right);
}

//interface of mergesort
void merge_sort_recursive(int array[], int length){
  int* temp = new int[length];
  merge_sort_recursive(array, temp, 0, length);
  delete []temp;
}

//interface of mergesort
void merge_sort_non_recursive(int array[], int length){
  int* temp = new int[length];
  for(int step = 1; step < length; step = step * 2){
    for(int left = 0; left < length; left = left + 2 * step){
      int middle = std::min(left + step, length);
      int right = std::min(left + 2 * step, length);
      merge(array, temp, left, middle, right);     
    }
  }
  delete []temp;
}

int main(){
    int a[] = { 3, 4, 2, 1, 7, 5, 8, 9, 0, 6};
    merge_sort_recursive(a, 10);
    for(int i = 0; i < 10; i++)
      std::cout << a[i] << " ";
    std::cout << std::endl;
    return 0;
}