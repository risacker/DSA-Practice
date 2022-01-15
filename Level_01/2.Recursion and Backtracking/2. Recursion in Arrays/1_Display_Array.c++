/*1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to print the elements of array from beginning to end each in a separate line.
4. For the above purpose complete the body of displayArr function. Don't change the signature.

Note -> The online judge can't force you to write the function recursively but that is what the spirit of question is. Write recursive and not iterative logic. The purpose of the question is to aid learning recursion and not test you.

Input Format
A number n
n1
n2
.. n number of elements

Output Format
n1
n2
.. n elements


Constraints
1 <= n <= 30
0 <= n1, n2, .. n elements <= 10

Sample Input
5
3
1
0
7
5

Sample Output
3
1
0
7
5*/

#include<bits/stdc++.h>
using namespace std;

void displayArr(int* arr, int n, int idx) {
    if (idx == n) 
      return;
    cout<<arr[idx]<<endl;
    displayArr(arr, n, idx + 1);
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
      cin>>arr[i];
    }
    displayArr(arr, n, 0);
}

/*Time Complexity : O(n)

Let"s try to understand our time complexity. 
Since we are making at most n recursion calls and in each call we are performing O(1) operations (printing a data is constant time) so our overall time complexity is n*O(1) = O(n).

SPACE COMPLEXITY : O(n)

Also, we know for each recursion call the parameters, address of the array are stored in the runtime stack, and since the recursive call stack is of n length it will also take n space in the stack. 
Although we are not using any array the space complexity will be O(n).*/