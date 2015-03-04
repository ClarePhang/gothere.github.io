/* 
* @Author: Beinan
* @Date:   2015-01-24 12:20:52
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-25 15:43:14
*/
#include<iostream>
#include<vector>
#include<list>


struct edge_node{
  int dest_id;
  int weight;
  
  edge_node(int dest_id, int weight)
    :dest_id(dest_id), weight(weight) {}

};

struct graph_ad_list{
  std::vector<std::list<edge_node>> ad_list;

  //n is the number of nodes
  graph_ad_list(int n):ad_list(n) {} 

  void add_edge(int source, int dest, int weight){
    edge_node new_edge(dest, weight);
    ad_list[source].push_back(new_edge); 
  }

  void dump(){
    //for each node
    for(int i = 0; i < ad_list.size(); i ++){
      //for each edge
      for(auto pos = ad_list[i].begin(); pos!=ad_list[i].end(); pos++){
        std::cout << "edge from " << i << " to " << pos->dest_id;
        std::cout << " weight: " << pos->weight << std::endl;
      }
    }
  }
}; 
