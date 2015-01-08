/* 
* @Author: Beinan
* @Date:   2015-01-04 17:51:36
* @Last Modified by:   Beinan
* @Last Modified time: 2015-01-04 18:12:57
*/

#include <iostream>

using namespace std;

int gcd_mod(int m, int n){
  if(n == 0)
    return m;
  else
    return gcd_mod(n, m % n);

}

int gcd_sub(int m, int n){
  if(m == n || n == 0)
    return m;
  if(m == 0)
    return n;
  if(m > n)
    return gcd_sub(n, m - n);
  else
    return gcd_sub(m, n - m);

}

//gcd binary
int gcd(int m, int n){
  if (m == n)
      return m;

  if (m == 0)
      return n;

  if (n == 0)
      return m;

  // look for factors of 2
  if (~m & 1) // m is even
  {
      if (n & 1) // n is odd
          return gcd(m >> 1, n);
      else // both m and n are even
          return gcd(m >> 1, n >> 1) << 1;
  }

  if (~n & 1) // m is odd, n is even
      return gcd(m, n >> 1);

  // reduce larger argument
  if (m > n)
      return gcd((m - n) >> 1, n);

  return gcd((n - m) >> 1, m);
}
int main(){
  cout << gcd_sub(99, 66) << endl;
  cout << gcd_mod(99, 66) << endl;
  cout << gcd(99, 66) << endl;
  return 0;
}