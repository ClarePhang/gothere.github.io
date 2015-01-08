/* 
* @Author: Beinan
* @Date:   2015-01-04 19:27:39
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-04 19:46:44
*/

#include <iostream>

using namespace std;

const char* strstr(const char* str1, const char* str2){
  if(str2 == nullptr)
    return nullptr;
  const char* p = str1;
  while(*p){ //whild *p is not '/0'
    const char *p1 = p, *p2 = str2;
    while(*p1 && * p2 && (*p1 == *p2)){
      p1 ++; p2 ++;
    } 
    if(!*p2) //*p2 == '\0'
      return p; //match!
    p++;
  }
  return nullptr;
}

int main(){
    cout << strstr("This is a simple string", "simple");
    return 0;
}