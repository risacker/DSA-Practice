/*1. You've to display the digits of a number.
2. Take as input "n", the number for which digits have to be displayed.
3. Print the digits of the number line-wise.

Input Format
"n" where n is any integer.

Output Format
d1
d2
d3
... digits of the number

Constraints
1 <= n < 10^9

Sample Input
65784383

Sample Output
6
5
7
8
4
3
8*/

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int power = 1;
    int temp = n;
    while (temp >= 10) {
        temp /= 10;
        power *= 10;
    }
    temp = n;
    while (power != 0) {
        int digit = temp / power;
        cout<<digit<<endl;
        temp = temp % power;
        power = power / 10;
    }
    return 0;
}