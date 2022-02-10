/*1. You are given an array(arr) of integers and a pivot.
2. You have to re-arrange the given array in such a way that all elements smaller or equal to pivot lie on the left side of pivot and all elements greater than pivot lie on its right side.
3. You have to achieve this in linear time.

Note -> For more information, watch question video.

Constraints
1 <= N <= 100000
-10^9 <= arr[i] <= 10^9
-10^9 <= pivot <= 10^9

Format
Input
An Integer n 
arr1
arr2..
n integers
An integer pivot

Output
Check the sample output and question video.

Example
Sample Input
5
7 
-2 
4 
1 
3
3

Sample Output
Swapping -2 and 7
Swapping 1 and 7
Swapping 3 and 4
-2 1 3 7 4 
*/

#include<bits/stdc++.h>
using namespace std;

void swap(int arr[],int i,int j){
    cout<<"Swapping "<<arr[i]<<" and "<<arr[j]<<endl;
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void partition(int arr[],int n,int pivot){
    int p1=-1;
    int itr=0;
    while(itr<n){
        if(arr[itr]<=pivot){
            swap(arr,itr,++p1);
        }
        itr++;
    }
}

void print(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){  
    int n;
    cin>>n;  
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }   
    int pivot;
    cin>>pivot;  
    partition(arr,n,pivot);
    print(arr,n);
}
