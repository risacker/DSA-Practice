/*1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing the elements of array a.
3. You are given a number k, representing the size of window.
4. You are required to find and print the maximum element in every window of size k.

e.g.
for the array [2 9 3 8 1 7 12 6 14 4 32 0 7 19 8 12 6] and k = 4, the answer is [9 9 8 12 12 14 14 32 32 32 32 19 19 19]

Constraints
0 <= n < 100000
-10^9 <= a[i] <= 10^9
0 < k < n

Format
Input
Input is managed for you

Output
Maximum of each window in separate line*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void slidingWindow(vector<int> & arr, int k, int size){
    int n = size;
    vector<int> ngr(n); 
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        int ele = arr[i];
        while(!st.empty() && ele >= arr[st.top()]){
            st.pop();
        }
        if(st.empty()){
            ngr[i] = n;
        }else{
            ngr[i] = st.top();
        }
        st.push(i);
    }
    
    vector<int> ans((n - k + 1), 0);
    int pc = 0;
    for(int i = 0; i < ans.size(); i++){
        if(pc < i){
            pc = i;
        }
        int ep = i + k;    // _----_ > Ending Point
        while(ep > ngr[pc]){
            pc = ngr[pc];
        }
        
        ans[i] = arr[pc];
    }   
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}

int main(){
    int n;
    cin >> n;   
    vector<int> arr(n);
    for(int i = 0; i < arr.size(); i++){
        cin >> arr[i];
    }  
    int k;
    cin >> k;  
    int size = arr.size();   
    slidingWindow(arr, k, size);
    return 0;
} 

/*Time Complexity: O(n)

Space Complexity: O(n)*/