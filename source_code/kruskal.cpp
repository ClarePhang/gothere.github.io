/* 
* @Author: Beinan
* @Date:   2015-01-25 21:09:07
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-25 21:51:05
*/

#include <iostream>
#include <vector>
#include <algorithm>

#include "graph_ad_list.h"
#include "disjoint_set.h"

using namespace std;

struct edge{
  int source, dest, weight;
  edge(int source, int dest, int weight): source(source),
    dest(dest), weight(weight) {}
};

bool compare_weight(edge a, edge b){
  return a.weight < b.weight;
}

graph_ad_list kruskal(graph_ad_list &g){
  
  vector<disjoint_set*> sub_sets(g.ad_list.size());

  //for each node, MAKE-SET(v)
  for(int i = 0; i < g.ad_list.size(); i ++)
    sub_sets[i] = new disjoint_set;

  vector<edge> edges;
  //for each node
  for(int i = 0; i < g.ad_list.size(); i ++){
    //for each edge
    for(auto pos = g.ad_list[i].begin(); pos!=g.ad_list[i].end(); pos++){
      edge edge(i, pos->dest_id, pos->weight);
      edges.push_back(edge);
    }
  }
  //sorting edges by weight
  std::sort(edges.begin(),edges.end(),compare_weight);
  
  //result graph
  graph_ad_list result(g.ad_list.size());    
  //for each edge
  for(int i = 0; i < edges.size(); i++){
    edge e = edges[i];
    //if source node and dest node are not in the same sub set
    if(sub_sets[e.source]->find_root() != sub_sets[e.dest]->find_root()){
      result.add_edge(e.source, e.dest, e.weight);
      sub_sets[e.source]->union_set(sub_sets[e.dest]);
    }
  }
  return result;
}

int main(){
    graph_ad_list g(5); 
    g.add_edge(0, 4, 1);
    g.add_edge(0, 1, 3);
    g.add_edge(1, 4, 4);
    g.add_edge(1, 2, 5);
    g.add_edge(2, 4, 6);
    g.add_edge(2, 3, 2);
    g.add_edge(3, 4, 7);
    
    graph_ad_list min_span_tree = kruskal(g);
    min_span_tree.dump();
    return 0;
}