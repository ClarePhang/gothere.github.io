/* 
* @Author: Beinan
* @Date:   2014-11-18 21:28:24
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-04 16:06:40
*/

public class QuickSort {
    public static void main(String[] args) {
      int[] a = { 4, 3, 7, 11, 2, 6, 5 };
      quick_sort(a, 0, 6);
      for(int v : a){
        System.out.print(v);
        System.out.print(" "); 
      }

    }

    public static void quick_sort(int[] a, int begin, int end) {
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
          int temp = a[left + 1];
          a[left + 1] = a[right];
          a[right] = temp; 
          right--; 
        }
      }
      a[left] = pivot_value;
      quick_sort(a, begin, left - 1);
      quick_sort(a, left + 1, end);
    }
}