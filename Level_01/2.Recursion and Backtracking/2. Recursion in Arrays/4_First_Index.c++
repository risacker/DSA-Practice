/*1. You are given a number n, representing the count of elements.
2. You are given n numbers.
3. You are given a number x. 
4. You are required to find the first index at which x occurs in array a.
5. If x exists in array, print the first index where it is found otherwise print -1.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

Input Format
A number n
n1
n2
.. n number of elements
A number x

Output Format
A number representing first index of occurence of x in array a or -1 if not found at all.

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
3*/

#include<bits/stdc++.h>
using namespace std;

int firstIndex(int* arr, int n, int idx, int x) {
    if (idx == n)
    {
      return -1;
    }
    if (arr[idx] == x)
    {
      return idx;
    }
    int fiisa = firstIndex(arr, n, idx + 1, x);
    return fiisa;
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
    int fi = firstIndex(arr, n, 0, x);
    cout<<fi<<endl;
}

/*Time Complexity : O(n)
The time complexity of this solution is O(n) as we are traversing an array and searching for an element.

SPACE COMPLEXITY : O(n)
As you know from the previous questions, since we did not take any extra memory, 
the space complexity is O(1), but if we consider stack space then it is O(n).*/