/*1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number x. 
4. You are required to find the last index at which x occurs in array a.
5. If x exists in array, print the last index where it is found otherwise print -1.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. 
Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

Input Format
A number n
n1
n2
.. n number of elements
A number x

Output Format
A number representing last index of occurence of x in array a or -1 if not found at all.

Constraints
1 <= n <= 10^4
0 <= n1, n2, .. n elements <= 10 ^ 3
0 <= x <= 10 ^ 3

Sample Input
6
15
11
40
4
4
9
4

Sample Output
4*/

#include<bits/stdc++.h>
using namespace std;

int lastIndex(int* arr, int n, int idx, int x) {
    if (idx == n) {
      return -1;
    }
    int liisa = lastIndex(arr, n, idx + 1, x);
    if (liisa == -1) {
      if (arr[idx] == x) {
        return idx;
      } 
      else {
        return -1;
      }
    }
    else {
        return liisa;
    }
    
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
      cin>>arr[i];
    }
    int x;
    cin>>x;
    int li = lastIndex(arr, n, 0, x);
    cout<<li<<endl;
}

/*Time Complexity : O(n)

As n (array"s length) calls are made and work is done corresponding to these n calls therefore the time complexity becomes O(n).

SPACE COMPLEXITY : O(1)

Since no extra space is used, therefore space complexity is constant, however you should know that if the recursion call stack is taken into account, 
then space complexity will be O(n) as there are n recursive calls.*/