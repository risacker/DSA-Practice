/*1. You've to print first n fibonacci numbers.
2. Take as input "n", the count of fibonacci numbers to print.
3. Print first n fibonacci numbers.

Input Format
n

Output Format
0
1
1
2
3
5
8
.. first n fibonaccis

Constraints
1 <= n < 40

Sample Input
10

Sample Output
0
1
1
2
3
5
8*/

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a=0,b=1,c;
    for(int i=0;i<=n;i++){
        cout<<a<<endl;
        c=a+b;
        a=b;
        b=c;
    }
    return 0;
}