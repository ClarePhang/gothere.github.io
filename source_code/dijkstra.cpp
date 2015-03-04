/* 
* @Author: Beinan
* @Date:   2015-02-01 14:54:24
* @Last Modified by:   Beinan
* @Last Modified time: 2015-02-07 20:12:14
*/

#include <iostream>

#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

#include "graph_ad_list.h"

using namespace std;

//dist maintains the distance from source to source
//prev stores the previous node in optimal path initialization
struct node{
  int id;
  int dist;
  int prev;
  bool processed;
  node():dist(INT_MAX), prev(-1), processed(false) {}
};

struct compare_node{
  bool operator()(node& a, node& b){
    return a.dist > b.dist;
  }
};

vector<node> dijkstra(graph_ad_list &g, int source){
  int node_count = g.ad_list.size();
  vector<node> nodes(node_count);
  
  for(int i = 0; i < node_count; i ++){
    nodes[i].id = i;
  }
  nodes[source].dist = 0;

  priority_queue<node, vector<node>, compare_node> node_pq;
  node_pq.push(nodes[source]);
  
  while(!node_pq.empty()){
    //get the node with the smallest dist
    node current_node = node_pq.top();
    node_pq.pop();
    //if the current node has been processed, skip
    if(current_node.processed)
      continue;
    //get all edges from the current node
    list<edge_node> edge_nodes = g.ad_list[current_node.id];
    //for each edge from current node
    for(auto edge_pos = edge_nodes.begin(); 
        edge_pos != edge_nodes.end(); edge_pos++){
      node& dest_node = nodes[edge_pos->dest_id];
      if(current_node.dist + edge_pos->weight < dest_node.dist){
        dest_node.dist = current_node.dist + edge_pos->weight;
        dest_node.prev = current_node.id; 
        node_pq.push(dest_node);
      }
    }
    current_node.processed = true;
    
  }
  
  return nodes;
}

void print_path(vector<node>& nodes, int node_id){
  if(nodes[node_id].prev == -1) //if reach the source
    cout << "Path: " << node_id; 
  else{
    print_path(nodes, nodes[node_id].prev);
    cout << "->" << node_id;
  }
}
int main(){
    graph_ad_list g(9); 
    g.add_edge(0, 1, 2);
    g.add_edge(0, 3, 9);
    g.add_edge(0, 4, 6);
    g.add_edge(1, 2, 1);
    g.add_edge(1, 4, 3);
    g.add_edge(2, 4, 1);
    g.add_edge(2, 6, 6);
    g.add_edge(3, 7, 4);
    g.add_edge(4, 3, 2);
    g.add_edge(4, 5, 9);
    g.add_edge(5, 6, 5);
    g.add_edge(5, 8, 1);
    g.add_edge(6, 8, 5);
    g.add_edge(7, 5, 1);
    g.add_edge(7, 8, 5);
    
    vector<node> result = dijkstra(g, 0);
    for(int i = 0; i < result.size(); i++){
      cout << "Print path and dist for node:" << result[i].id << endl;
      print_path(result, result[i].id);
      cout << endl << "Dist:" << result[i].dist << endl;
    }
    return 0;
}