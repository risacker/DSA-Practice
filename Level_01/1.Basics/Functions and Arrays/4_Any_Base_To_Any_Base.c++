/*1. You are given a number n.
2. You are given a base b1. n is a number on base b.
3. You are given another base b2.
4. You are required to convert the number n of base b1 to a number in base b2.

Input Format
A number n
A base b1
A base b2

Output Format
A number of base b2 equal in value to n of base b1.

Constraints
0 <= n <= 512
2 <= b1 <= 10
2 <= b2 <= 10

Sample Input
111001
2
3

Sample Output
2010*/

#include<bits/stdc++.h>
using namespace std;

// Function for converting number from decimal to base-b number system
int decimalToAnyBase(int n, int b) {
    int p = 1; //Power variable - increases places
    int rv = 0; //Return value - stores answer
    while (n > 0)
    {
      int dig = n % b; //Digit-stores remainder at each step
      rv += (dig * p); //placing digit at right place
      p *= 10; // increasing power; to the next place
      n = n / b; // dividing the number by base number
    }
    return rv; //Final converted number
}

// Function for converting number from base-b number system to decimal
int anyBaseToDecimal(int n, int b) {
    int rv = 0;
    int p = 0;
    while (n > 0)
    {
      int dig = n % 10; //storing rightmost digit as remainder
      rv += (dig * pow(b, p)); // we use Math.pow(base,power) to calculate multiplier
      p++; // incrementing power
      n /= 10; // removing rightmost digit
    }
    return rv;
}

int getValue(int n, int src, int dest){
    int decimalValue = anyBaseToDecimal(n, src); //Converting to decimal
    int finalBaseValue = decimalToAnyBase(decimalValue, dest); // Converting to destination base
    return finalBaseValue;
}

int main(){
    int n,sourceBase,destBase;
    cin>>n>>sourceBase>>destBase;
    int value = getValue(n, sourceBase, destBase);
    cout<<value;
    return 0;
}

/* Time Complexity: O(log10(n) + log10(n)) = O(log10(n))
Space Complexity: O(1) */