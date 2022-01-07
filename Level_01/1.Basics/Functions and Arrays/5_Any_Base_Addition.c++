/*1. You are given a base b.
2. You are given two numbers n1 and n2 of base b.
3. You are required to add the two numbes and print their value in base b.

Input Format
A base b
A number n1
A number n2

Output Format
A number representing the sum of n1 and n2 in base b.

Constraints
2 <= b <= 10
0 <= n1 <= 256
0 <= n2 <= 256

Sample Input
8
777
1

Sample Output
1000*/

#include<bits/stdc++.h>
using namespace std;
int getSum(int b, int n1, int n2) {
    int rv = 0;
    int p = 1;
    int c = 0;
    while ( n1 > 0 || n2 > 0 || c > 0) //while numbers are not-nero or carry is non-zero
    {
      int d1 = n1 % 10; //extracting digits
      int d2 = n2 % 10;
      int d = d1 + d2 + c; //adding up extracted digits
      c = d / b; //storing carry for next addition
      d = d % b;
      rv += d * p;
      p *= 10;
      n1 /= 10;
      n2 /= 10;
    }
    return rv;
}

int main(){
    int b,n1,n2;
    cin>>b>>n1>>n2;
    int d = getSum(b, n1, n2);
    cout<<d<<endl;
    return 0;
}

/*Time Complexity: For finding time complexity always try to look for loops (for loops, or while loops) and find the iterations. Here we can see the while loop will run as long as n1, n2, or c is non-zero. And in each iteration what operation are we performing? Division. Hence it might be logarithmic. Clearly, the loop will run at least the number of digits of the maximum number. Why maximum? Because we always look for the upper bound. There might be one extra for the carry.
If n is a number then what is the length ( number of digits ) in that number? (log10 n)
If you are not aware of why this is the case, please revisit the article Digits of a number.
So, we can say the Big-O for this problem will be (log10(max(n1, n2) + 1), but we can ignore the 1 since it's a constant.

Space Complexity: O(1)*/