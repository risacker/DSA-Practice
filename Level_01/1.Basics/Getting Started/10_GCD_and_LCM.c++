/*1. You are required to print the Greatest Common Divisor (GCD) of two numbers.
2. You are also required to print the Lowest Common Multiple (LCM) of the same numbers.
3. Take input "num1" and "num2" as the two numbers.
4. Print their GCD and LCM.

Input Format
num1
num2
.. the numbers whose GCD and LCM we have to find.

Output Format
a
b
.. where 'a' and 'b' are the GCD and LCM respectively.

Constraints
2 <= n <= 10^9

Sample Input
36
24

Sample Output
12
72*/

#include<iostream>
using namespace std;
int main(){
    int n1,n2;
    cin>>n1>>n2;
    int temp1 = n1;
    int temp2 = n2;
    while (n1 % n2 != 0)
    {
      int remainder = n1 % n2;
      n1 = n2;
      n2 = remainder;
    }
    int gcd = n2;
    int lcm = (temp1 * temp2) / gcd;
    cout<<gcd<<endl;
    cout<<lcm<<endl;
    return 0;
}

/*Time Complexity:
O(min(a, b))

Space Complexity:
O(1)*/