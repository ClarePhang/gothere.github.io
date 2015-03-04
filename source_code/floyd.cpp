/* 
* @Author: Beinan
* @Date:   2015-02-15 18:20:19
* @Last Modified by:   Beinan
* @Last Modified time: 2015-02-15 19:41:34
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void print_path(vector<vector<int>> &next, int i, int j){
  cout << "Printing path from " << i << " to " << j << ":";
  if(next[i][j] == -1 ){
    cout << "no path found" << endl;
    return;
  }
  cout << i;
  while(i != j){
    i = next[i][j];
    cout << "->" <<i;
  }
  cout << endl;
}
int main(){
    vector<vector<int>> d = {
      {0, 9999, -2 ,9999},
      {4, 0, 3, 9999},
      {9999, 9999, 0, 2},
      {9999, -1, 9999, 0}
    };
    vector<vector<int>> next {
      {-1, -1, 2 ,-1},
      {0, -1, 2, -1},
      {-1, -1, -1, 3},
      {-1, 1, -1, -1}
    };
    for(int k = 0; k < d.size(); k ++)
      for(int i = 0; i < d.size(); i++)
        for(int j = 0; j < d.size(); j++)
          if(d[i][j] > d[i][k] + d[k][j]){
            d[i][j] = d[i][k] + d[k][j];
            next[i][j] = next[i][k];
          }

    for(int i = 0; i < d.size(); i++, cout << endl)
        for(int j = 0; j < d.size(); j++)
          cout << d[i][j] << " ";

    for(int i = 0; i < d.size(); i++, cout << endl)
        for(int j = 0; j < d.size(); j++)
          print_path(next, i, j);        
    return 0;
}