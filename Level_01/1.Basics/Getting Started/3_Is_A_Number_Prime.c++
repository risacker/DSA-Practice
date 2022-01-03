/*1. You've to check whether a given number is prime or not.
2. Take a number "t" as input representing count of input numbers to be tested.
3. Take a number "n" as input "t" number of times.
4. For each input value of n, print "prime" if the number is prime and "not prime" otherwise.

Input Format
A number t
A number n
A number n
.. t number of times

Output Format
prime
not prime
not prime
.. t number of times

Constraints
1 <= t <= 10000
2 <= n < 10^9

Sample Input
5
13
2
3
4
5

Sample Output
prime
prime
prime
not prime
prime

A prime number is a number which is either divisible by 1 or the number itself.*/

#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
      int n;
      cin>>n;
      int d=2; //set divisor=2
      while (d * d <= n) {
        if (n % d == 0) {
          break;
        }
        d++;
      }
      if (d * d > n) {
        cout<<"prime";
      } 
      else {
        cout<<"not prime";
      }
    }
    return 0;
}

/*Time Complexity:
O(t * sq.rt(n)).

Space Complexity:
O(1)*/