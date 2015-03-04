/* 
* @Author: Beinan
* @Date:   2015-02-07 18:40:39
* @Last Modified by:   Beinan
* @Last Modified time: 2015-02-07 20:03:36
*/

var data = [4.2,5.4,3.2,2.7,1.4,2.8,4.3,5.2,2.8,4.3,2.2,5.7];
var sum = 8;
var hash={};
for(var i = 0; i < data.length; i++){
  if(hash[sum - data[i]]){
    console.log('Found:' + data[i] + "," + (sum - data[i]));
    break;    
  }
  if(!hash[data[i]]){
    hash[data[i]] = true;
  }
  
}