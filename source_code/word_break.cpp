/* 
* @Author: Beinan
* @Date:   2015-02-15 20:11:38
* @Last Modified by:   Beinan
* @Last Modified time: 2015-02-15 20:51:49
*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void print_result(vector<string>& result, int length){
  if(length == 0)
    return;
  string word = result[length];
  print_result(result, length - word.length());
  cout << " " << word;
}

void word_break(unordered_set<string> &dict, string str){
  vector<string> result;
  result.resize(str.length() + 1, "");
  for(int i = 0; i <= str.length(); i++){
    string word = str.substr(0, i);
    if(dict.count(word) > 0){
      result[i] = word;
      continue;
    }
    for(int j = 0; j < i; j++){
      if(result[j] != ""){
        string word = str.substr(j, i-j);
        if(dict.count(word) > 0){
          result[i] = word;
          break;
        }
      }
    }  
  }

  if(result[str.length()] != ""){
    print_result(result, str.length());
    
  }
}

int main(){
    unordered_set<string> dict = 
      {"word", "ord", "break", "problem", "lem", "pro", "db" , "wor"};

    word_break(dict,"wordbreakproblem");
    return 0;
}