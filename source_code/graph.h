/* 
* @Author: Beinan
* @Date:   2015-01-25 15:20:50
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-25 15:44:12
*/
#include<iostream>
#include<vector>
#include<stack>
#include<queue>

class GraphAdMatrix{
private: 
  std::vector<std::vector<int>> g;  
public:  
  GraphAdMatrix(std::vector<std::vector<int>> &g): g(g){
  }

  void dfs_recursive(int start_node_id){
    std::vector<bool> visited(g.size());    
    visit(visited, start_node_id);  
    
  }

  void dfs(int start_node_id){
    std::vector<bool> visited(g.size());
    std::stack<int> s;
    s.push(start_node_id);
    while(s.size()){
      int node_id = s.top();
      s.pop();
      if(!visited[node_id]){ //if node is not labeled as discovered
        visited[node_id] = true; // label node as discovered
        std::cout << "dfs visiting " << node_id << std::endl;    
        for(int i = 0; i < g.size(); i++){
          if(g[node_id][i] == 1){
              s.push(i);
          }
        }     
      }
    }  

  }

void bfs(int start_node_id){
    std::vector<bool> visited(g.size());
    std::queue<int> s;
    s.push(start_node_id);
    while(s.size()){
      int node_id = s.front();
      s.pop();
      if(!visited[node_id]){ //if node is not labeled as discovered
        visited[node_id] = true; // label node as discovered
        std::cout << "bfs visiting " << node_id << std::endl;    
        for(int i = 0; i < g.size(); i++){
          if(g[node_id][i] == 1){
              s.push(i);
          }
        }     
      }
    }  
}
private:
  void visit(std::vector<bool> &visited, int node_id){
    visited[node_id] = true;
    std::cout << "dfs recursively visiting " << node_id << std::endl;
    for(int i = 0; i < visited.size(); i++){
      if(!visited[i] && g[node_id][i] == 1){
        visit(visited, i);
      }
    }
  }
};