/*1. You are given a number n.
2. You are given a base b. n is a number on base b.
3. You are required to convert the number n into its corresponding value in decimal number system.

Input Format
A number n
A base b

Output Format
A decimal number representing corresponding value of n in base b.

Constraints
0 <= d <= 1000000000
2 <= b <= 10
  
Sample Input
111001
2

Sample Output
57*/

#include<bits/stdc++.h>
using namespace std;
int toDecimal(int n, int b){
    int multiplier = 0, num = 0;
    while (n > 0) {
      int remainder = n % 10;
      n = n / 10;
      num += remainder * pow(b, multiplier);
      multiplier++;
    }
    return num;
}

int main(){
    int n,b;
    cin>>n>>b;
    int ans=toDecimal(n,b);
    cout<<ans<<endl;
    return 0;
}

/*Time Complexity: O(log10 n)

Space Complexity: O(1)*/