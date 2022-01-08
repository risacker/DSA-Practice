/*1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to calculate the inverse of array a.
The only difference is the range of values is from 0 to n - 1, instead of 1 to n.

Input Format
Input is managed for you

Output Format
Output is managed for you

Constraints
0 <= n < 10^7
The only difference is the range of values is from 0 to n - 1, instead
of 1 to n

Sample Input
5
4
0
2
3
1

Sample Output
1
4
2
3
0*/

#include<iostream>
using namespace std;

int* inverse(int* arr, int n){
    int* inv = new int[n];
    for(int i = 0 ; i < n; i++){
        inv[arr[i]] = i;
    }
    return inv;
}

void display(int* arr, int n){
    for(int i = 0 ; i < n; i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }  
    int* inv = inverse(arr,n);
    display(inv,n);
    return 0;
}

/*Time Complexity: O(n)
 
A "for" loop is used to put the index value as data in a new array from the input array; travelling the n sized array makes the time complexity O(n).

SPACE COMPLEXITY: O(n)

As a new array (inv) of size n has been used, therefore space complexity becomes O(n).*/