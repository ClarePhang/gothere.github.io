/* 
* @Author: Beinan
* @Date:   2015-02-07 20:38:18
* @Last Modified by:   Beinan
* @Last Modified time: 2015-02-07 21:28:45
*/

#include <iostream>

using namespace std;

const unsigned PRIME_BASE = 1;

int rabin_karp(const string& source, const string& pattern){
  unsigned source_hash = 0, pattern_hash = 0;
  unsigned power = 1;
  size_t pattern_length = pattern.length();
  for(int i = 0; i < pattern.length(); i++){
    pattern_hash = pattern_hash * PRIME_BASE + pattern[i];
    source_hash = source_hash * PRIME_BASE + source[i]; 
    power *= PRIME_BASE; //for rolling   
  }
  if(pattern_hash == source_hash && pattern == source.substr(0, pattern_length))
    return 0;
  for(int i = pattern.length(); i < source.length(); i++){
    source_hash = source_hash*PRIME_BASE + source[i];
    source_hash = source_hash - power * source[i - pattern.length()];
    if(pattern_hash == source_hash && pattern == source.substr(i - (pattern.length() - 1), pattern_length)){
      return i - (pattern.length() - 1);
    }
  }
  return -1;  

}    
int main(){
    cout << rabin_karp("cadabbbcccddd", "bc");
    return 0;
}