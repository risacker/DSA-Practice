/*1. You are given an array(arr) of integers.
2. You have to sort the given array in increasing order using radix sort.

Constraints
1 <= N <= 10000
0 <= arr[i] <= 10^8

Format
Input
An Integer n 
arr1
arr2..
n integers

Output
Check the sample ouput and question video.

Example
Sample Input
5
7 
2 
4 
1 
3

Sample Output
After sorting on 1 place -> 1 2 3 4 7 
1 2 3 4 7 */

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

void Display(vector<int>& arr){
    for(int ele : arr){
        cout<< ele << " ";
    }
}

void countsort(vector<int> &arr, int d){
    int fsize = 10;
    vector<int> freq(fsize, 0);   
    for(int i = 0; i < arr.size(); i++){
        int idx = (arr[i] / d) % 10;
        freq[idx]++;
    }
    
    for(int i = 1; i < freq.size(); i++){
        freq[i] = freq[i] + freq[i - 1];
    }
    
    vector<int> ans(arr.size(), 0);  
    for(int i = arr.size() - 1; i >= 0; i--){
        int idx = (arr[i] / d) % 10;
        ans[freq[idx]-1] = arr[i];
        freq[idx]--;
    }   
    for(int i = 0; i < arr.size(); i++){
        arr[i] = ans[i];
    }   
    cout<< "After sorting on " << d << " place -> ";
    Display(arr);
    cout << endl;
}

void radixSort(vector<int> &arr){
    int maxVal = INT_MIN;
    for(int ele : arr){
        maxVal = max(maxVal, ele);
    }  
    int exp = 1;
    while(exp <= maxVal){
        countsort(arr, exp);
        exp *= 10;
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);    
    for(int i = 0; i < n; i++){    
        cin >> arr[i];
    }  
    radixSort(arr);
    Display(arr);
    return 0;
}