/* 
* @Author: Beinan
* @Date:   2015-01-25 15:20:50
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-25 16:39:32
*/

#include <iostream>
#include "graph.h"

using namespace std;


int main(){
    vector<vector<int>> G = {
      {0, 0, 1 ,1},
      {0, 0, 1, 1},
      {0, 1, 0, 0},
      {0, 1, 1, 0}
    };
    GraphAdMatrix graph(G);
    graph.dfs_recursive(0);
    graph.dfs(0);
    graph.bfs(0);
    
    return 0;
}