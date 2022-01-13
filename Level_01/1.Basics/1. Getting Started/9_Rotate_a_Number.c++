/*1. You are given two numbers n and k. You are required to rotate n, k times to the right. If k is positive, rotate to the right i.e. remove rightmost digit and make it leftmost. Do the reverse for negative value of k. Also k can have an absolute value larger than number of digits in n.
2. Take as input n and k.
3. Print the rotated number.
4. Note - Assume that the number of rotations will not cause leading 0's in the result. e.g. such an input will not be given
   n = 12340056
   k = 3
   r = 05612340

Input Format
"n" where n is any integer.
"K" where k is any integer.

Output Format
"r", the rotated number

Constraints
1 <= n < 10^9
-10^9 < k < 10^9

Sample Input
562984
2

Sample Output
845629*/

#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int nod = 0;  //number of digits
    int temp = n; //temporarily storing number to perform division
    while (temp != 0)
    {
      temp /= 10;
      nod++;
    }
    k = k % nod;  // to deal with k values > nod
    if (k < 0) // to check if k is negative
    {
      k = k + nod; // to accomodate -k cases
    }
    int div = 1;  //initialize divisor = 1
    int mult = 1; //initialize multiplier = 1
    for (int i = 1; i <= nod; i++)
    {
      if (i <= k) //while the iterator is less than k
      { //we increase the value of divisor
        div *= 10;
      }
      else         //or else we increase the value of multiplier
      {
        mult *= 10;
      }
    }
    int quo = n / div;    // extracting the quotient
    int rem = n % div;    // extracting the remainder
    int r = rem * mult + quo; //forming the rotated number
    cout<<r<<endl;
    return 0;
}

/* Time Complexity: O(log10 n) 
Space Complexity: {O(1)} */