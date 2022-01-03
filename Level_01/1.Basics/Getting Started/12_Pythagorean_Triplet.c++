/*1. You are required to check if a given set of numbers is a valid pythagorean triplet.
2. Take as input three numbers a, b and c.
3. Print true if they can form a pythagorean triplet and false otherwise.

Input Format
a, an integer
b, an integer
c, an integer

Output Format
true if the numbers form a pythagorean triplet and false otherwise

Constraints
1 <= a <= 10^9
1 <= b <= 10^9
1 <= c <= 10^9

Sample Input
5 3 4

Sample Output
true*/

#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int max = a;
    if (b >= max)
      max = b;
    if (c >= max)
      max = c;
    if (max == a){
      if((b * b + c * c) == (a * a))
        cout<<"true"<<endl;
      else
        cout<<"false"<<endl;
    }
    else if (max == b){ 
      if((a * a + c * c) == (b * b))
        cout<<"true"<<endl;
      else
        cout<<"false"<<endl;
    }
    else{
      if((a * a + b * b) == (c * c))
        cout<<"true"<<endl;
      else
        cout<<"false"<<endl;
    }
    return 0;
}