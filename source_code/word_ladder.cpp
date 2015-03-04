/* 
* @Author: Beinan
* @Date:   2015-02-08 17:34:43
* @Last Modified by:   Beinan
* @Last Modified time: 2015-02-08 18:09:13
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct word_node{
  string word;
  bool visited;
  string previous;
  word_node(string word): word(word), visited(false), previous("") {}
};

//print path
void print_result(unordered_map<string, word_node*>& word_map, word_node* node){
  if(node->previous != ""){
    print_result(word_map, word_map[node->previous]);
  }
  cout << " -> " << node->word;
}

void word_ladder(vector<string>& words, string start, string end){
  unordered_map<string, word_node*> word_map;
  for(int i = 0; i < words.size(); i++){ //for each word, build word_node
    word_node* node = new word_node(words[i]);
    word_map[words[i]] = node;
  }
  queue<word_node*> q;
  word_map[start]->visited = true;
  q.push(word_map[start]);
  while(!q.empty()){
    word_node* current_node = q.front();
    q.pop();
    for(int i = 0; i < current_node->word.length(); i++){//for each char in word
      for(char c = 'a'; c <= 'z'; c++){ //from a to z
        string word = current_node->word;
        word[i] = c;
        if(word == end){ //we found a solution
          print_result(word_map, current_node);
          cout << " -> " << end << endl;
          return;
        }
        if(word_map.count(word) && !word_map[word]->visited){ //exist in the word map && not visited
          word_map[word]->visited = true;
          word_map[word]->previous = current_node->word;
          cout << "visiting " << word << " from " << current_node->word << endl;
          q.push(word_map[word]);
        }
      
      }  
    }
  }

}
int main(){
    
    vector<string> words = {"hot","dot","hit", "dog","lot","log", "cog"};
    string start = "hit";
    string end = "cog";
    word_ladder(words, start, end);    
    return 0;
}