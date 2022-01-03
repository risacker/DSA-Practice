/*1. You've to count the number of digits in a number.
2. Take as input "n", the number for which the digits has to be counted.
3. Print the digits in that number.

Input Format
"n" where n is any integer.

Output Format
"d" where d is the number of digits in the number "n

Constraints
1 <= n < 10^9

Sample Input
65784383

Sample Output
8*/

#include<iostream>
using namespace std;
int main(){
    int digit = 0,n;
    cin>>n;
    while (n != 0)
    {
      n = n / 10;
      digit++;
    }
    cout<<digit<<endl;
    return 0;
}