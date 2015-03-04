/* 
* @Author: Beinan
* @Date:   2015-02-07 20:06:08
* @Last Modified by:   Beinan
* @Last Modified time: 2015-02-07 20:14:09
*/

#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    int array[] = {2,5,3,4,5,1,23,5,6,3,5,7};
    int sum = 11;
    unordered_set<int> hash_set;
    for(int i = 0; i < 12; i++){
      if(hash_set.count(sum - array[i])){
        cout << "Found:" << array[i] << "," << sum-array[i] << endl;
      }
      hash_set.insert(array[i]);
    }
    return 0;
}