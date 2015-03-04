/* 
* 
* Longest common subsequence problem
* @Author: Beinan
* @Date:   2015-02-15 16:18:25
* @Last Modified by:   Beinan
* @Last Modified time: 2015-02-15 17:45:33
*/

#include <iostream>
#include <algorithm>

using namespace std;


int lcs_recursive(char a[], int a_length, char b[], int b_length){
  static int count = 0;
  cout << ++count << endl;
  if(a_length == 0 || b_length == 0){
    return 0;
  } else if(a[a_length - 1] == b[b_length - 1]){
    return 1 + lcs_recursive(a, a_length - 1, b, b_length - 1);
  } else {
    int reduce_a = lcs_recursive(a, a_length - 1, b, b_length);
    int reduce_b = lcs_recursive(a, a_length, b, b_length - 1);
    return max(reduce_a, reduce_b);
  }
}

int lcs_dp(char a[], int a_length, char b[], int b_length){
  vector<vector<int>> value_table;
  value_table.resize(a_length + 1, vector<int>(b_length, 0)); //init value in value_table

  for (int i=0; i<=a_length; i++)
   {
     for (int j=0; j<=b_length; j++)
     {
       if (i == 0 || j == 0)
         value_table[i][j] = 0;  
       else if (a[i-1] == b[j-1])
         value_table[i][j] = value_table[i-1][j-1] + 1;  
       else
         value_table[i][j] = max(value_table[i-1][j], value_table[i][j-1]);
     }
   }
   return value_table[a_length][b_length];
}

int main(){
    char a[] = "ABCDGH";
    char b[] = "AEDFHR";
    cout << lcs_recursive(a, 6, b, 6) << endl;
    cout << lcs_dp(a, 6, b, 6) << endl;
    return 0;
}