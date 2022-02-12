/*1. You are given an array(arr) of integers.
  2. You have to sort the given array in increasing order using count sort.

Constraints
1 <= N <= 10000
-10^8 <= arr[i] <= 10^8

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
-2 
4 
1 
3

Sample Output
-2
1
3
4
7
*/

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

void countsort(vector<int> &arr, int max, int min){
    int fsize = max - min + 1;
    vector<int> freq(fsize, 0);
    
    for(int i = 0; i < arr.size(); i++){
        int idx = arr[i] - min;
        freq[idx]++;
    }
    
    for(int i = 1; i < freq.size(); i++){
        freq[i] = freq[i] + freq[i - 1];
    }
    
    vector<int> ans(arr.size(), 0);
    
    for(int i = arr.size() - 1; i >= 0; i--){
        int idx = arr[i] - min;
        ans[freq[idx]-1] = arr[i];
        freq[idx]--;
    }
    
    for(int i = 0; i < arr.size(); i++){
        arr[i] = ans[i];
    }
}

void Display(vector<int>& arr){
    for(int ele : arr){
        cout<< ele << endl;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n, 0);   
    for(int i = 0; i < n; i++){    
        cin >> arr[i];
    }  
    int maxi = (int)-1e9;
    int mini = (int)1e9;  
    for(int i = 0; i < n; i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }  
    countsort(arr, maxi, mini);
    Display(arr);
    
}