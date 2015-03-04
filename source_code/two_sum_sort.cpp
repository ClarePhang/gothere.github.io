/* 
* @Author: Beinan
* @Date:   2015-01-08 20:09:47
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-08 20:47:58
*/

#include <iostream>
#include <algorithm>

using namespace std;

void two_sum_naive(int a[], int length, int target){
  for(int i = 0; i < length; i++){
    for(int j = i + 1; j < length; j++){
      if(a[i] + a[j] == target){
        cout << "Result found:" << a[i] << "," << a[j] << endl;
      }
    }
  }
}


void two_sum_sorted(int a[], int length, int target){
  int left = 0, right = length - 1;
  while(left < right){
    int sum = a[left] + a[right];
    if(sum > target)
      right--;
    else if(sum < target)
      left ++;
    else{
      cout << "Result found(sorted array):" << a[left] << "," << a[right] << endl;
      left ++; right --;
    }
  }
}
int main(){
    int a[] = { 3, 4, 2, 1, 7, 5, 8, 9, 0, 6};
    two_sum_naive(a, 10, 9);
    cout << "2sum algorighm for sorted array\n";
    sort(a, a + 10);
    //two_sum_sorted(a, 10, 9);
    return 0;
}