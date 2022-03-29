/*1. You will be given an Array with its length
 2. You will also be given an integral value k
 3. You need to find k largest elements from the given array
 4. Input is handled for you
 5. It is a functional problem ,please do not modify main()

Constraints
1 <= N <= 100
K <= N
-1000 <= C[i] <= 1000

Format
Input
Input is handled for you

Output
Output MUST be in descending order

Example
Sample Input
8
44 -5 -2 41 12 19 21 -6 
2

Sample Output
44 41*/

#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> const& arr, int k){
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 0; i < k; i++){
    pq.push(arr[i]);
  }
  for(int i = k; i < arr.size(); i++){
    if (arr[i] > pq.top())
    {
      pq.pop();
      pq.push(arr[i]);
    }
  }
  return pq.top();
}

int main(){
  vector<int>arr;
  int n;
  cin>>n;
  for(int i = 0 ; i < n; i++){
    int data;
    cin>>data;
    arr.push_back(data);
  }
  int k;
  cin>>k;
  for(int i = k; i > 0; i--)
    cout<<findKthLargest(arr, i)<<endl;
}

/*Time Complexity: O((n log(k))

The time complexity of for loop (k log(k) + 2((n-k) log(k))).
The time complexity of the while loop (k log(k)).Which sum up to O(n log(k)).

Space Complexity: O(k)

The space complexity for the function O(k), which is the size of the priority queue used.*/