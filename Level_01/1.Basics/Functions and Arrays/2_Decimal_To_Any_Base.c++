/*1. You are given a decimal number n.
2. You are given a base b.
3. You are required to convert the number n into its corresponding value in base b.

Input Format
A number n
A base b

Output Format
A number representing corresponding value of n in number system of base b

Constraints
0 <= d <= 512
2 <= b <= 10
  
Sample Input
57
2

Sample Output
111001*/

#include<iostream>
using namespace std;
// Function for converting number from decimal to base-b number system
int getBase(int n, int b){
   int p = 1; //Power variable - increases places
   int rv = 0; //Return value - stores answer
   while (n > 0){
      int dig = n % b; //Digit-stores remainder at each step
      rv += (dig * p); //placing digit at right place
      p *= 10; // increasing power; to the next place
      n = n / b; // dividing the number by base number
    }
    return rv; //Final converted number
} 

int main(){
    int n,b;
    cin>>n>>b;
    int ans=getBase(n,b);
    cout<<ans<<endl;
    return 0;
}

/*Time Complexity: O(log10 n)

Space Complexity: O(1)*/