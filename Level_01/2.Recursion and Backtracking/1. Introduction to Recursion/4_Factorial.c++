/*1. You are given a number n.
2. You are required to calculate the factorial of the number. Don't change the signature of factorial function.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is.
Write recursive and not iterative logic. 
The purpose of the question is to aid learning recursion and not test you.

Input Format
A number n

Output Format
factorial of n

Constraints
0 <= n <= 10

Sample Input
5

Sample Output
120*/

#include<iostream>
using namespace std;

int factorial(int n) {
    if (n == 1) { //1
      return 1;
    }

    int fnm1 = factorial(n - 1); //2
    int fn = n * fnm1;  //3
    return fn;  //4
}

int main(){
    int n; 
    cin>>n;
    int f=factorial(n);
    cout<<f<<endl;
}

/*Time Complexity : O(n)

This time complexity is linear because a recursion call is made.

SPACE COMPLEXITY : O(1)

As no extra space is required, therefore space complexity is constant. 
However, if we include the space used in the recursive stack then the space complexity is O(n).*/