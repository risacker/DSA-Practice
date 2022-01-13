/*1. You are given a number x.
2. You are given another number n.
3. You are required to calculate x raised to the power n. Don't change the signature of power function.

Note1 -> The previous version expects the call stack to be of n height. This function expects call function to be only log(n) high.

Note2 -> The online judge can't force you to write the function recursively but that is what the spirit of question is. 

Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

Input Format
A number x
A number n

Output Format
x raised to the power n

Constraints
1 <= x <= 10
0 <= n <= 9

Sample Input
2
5

Sample Output
32*/

#include<iostream>
using namespace std;

int power(int x, int n) {
    if (n == 0) {
      return 1;
    }
    int xpnb2 = power(x, n / 2);
    // n/2 will automatically get floor value
    // since it is type casted to int.
    int xpn = xpnb2 * xpnb2;
    if (n % 2 == 1) {
      xpn = xpn * x;
    }
    return xpn;
}

int main(){
    int x,n; 
    cin>>x>>n;
    int p=power(x,n);
    cout<<p<<endl;
}

/*Time Complexity : O(log2 n)

Since you are recursively calling for a subproblem with n/2 from n, hence at max log2 (n) recursive calls will be made. 
You can also count the number of recursive calls in the call stack. 
So the time complexity turns out to be log2 (n) (which is independent of the value of x).

SPACE COMPLEXITY : O(1)

There is no data structure used, thus no auxiliary space is used. Hence, space complexity is O(1).*/