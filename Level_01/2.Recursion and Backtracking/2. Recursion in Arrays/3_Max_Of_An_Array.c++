/*1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are required to find the maximum of input. 
4. For the purpose complete the body of maxOfArray function. Don't change the signature.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

Input Format
A number n
n1
n2
.. n number of elements

Output Format
A number representing max

Constraints
1 <= n <= 10^4
0 <= n1, n2, .. n elements <= 10 ^9

Sample Input
6
15
30
40
4
11
9

Sample Output
40*/

#include<bits/stdc++.h>
using namespace std;

int maxOfArray(int* arr, int n, int idx) {
    if (idx >= n)
    {
      return INT_MIN;  //we have the constraint that the size of array will not be zero hence we have not considered that case here
    }
    int misa = maxOfArray(arr, n, idx + 1); //misa stands for maximum in smaller array
    if (arr[idx] > misa)
    {
      return arr[idx];
    }
    return misa;
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
      cin>>arr[i];
    }
    int m = maxOfArray(arr, n, 0);
    cout<<m;
}

/*Time Complexity : O(n)
The time complexity of the above solution is O(n). This is because we have iterated the array twice. 
Once while going into the recursion and the other time while coming out of it. So, n elements were visited twice: n+n= 2n, O(2n)=O(n).

SPACE COMPLEXITY : O(1)
The space complexity will be O(1) as we have not used any extra space. 
If we consider the recursion space, it will be O(n) i.e. the maximum height of the recursion stack.*/