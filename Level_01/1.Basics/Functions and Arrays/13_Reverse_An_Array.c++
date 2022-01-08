/*1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to reverse the contents of array a.

Input Format
Input is managed for you

Output Format
Output is managed for you

Constraints
0 <= n < 10^4
-10^9 <= a[i] <= 10^9

Sample Input
5
1
2
3
4
5

Sample Output
5 4 3 2 1*/

#include<iostream>
using namespace std;

void reverse(int* arr, int n){
    int left = 0;
    int right = n - 1;  
    while(left < right){
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

void display(int* arr, int n){
    for(int i = 0 ; i < n; i++){
        cout<<arr[i]<<" ";
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
    reverse(arr,n);
    display(arr,n);
    return 0;
}

/*Time Complexity : O(n) since we have traversed the entire array once.

SPACE COMPLEXITY : O(1) since we have not used any extra language. */