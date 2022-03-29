/*1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. The array is nearly sorted. Every element is at-max displaced k spots left or right to it's position in the sorted array. 
Hence it is being called k-sorted array.
4. You are required to sort and print the sorted array.

Note -> You can use at-max k extra space and nlogk time complexity.

Constraints
1 <= n <= 30
0 <= n1, n2, .. n elements <= 100
0 < k <= n

Format
Input
Input is managed for you

Output
Print the elements of sorted array in separate lines.

Example
Sample Input
9
3
2
4
1
6
5
7
9
8
3

Sample Output
1
2
3
4
5
6
7
8
9*/

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i < n;i++){
		cin>>arr[i];
	}
	int k;
	cin>>k;
	priority_queue<int,vector<int>,greater<int>> p;
	for(int i = 0;i <= k;i++){
		p.push(arr[i]);
	}
	for(int i = k+1;i < n;i++){
		cout<<p.top()<<endl;
		p.pop();
		p.push(arr[i]);
	}
	while(p.size() > 0){
		cout<<p.top()<<endl;
		p.pop();
	}
}

/*Time Complexity:O(n x logk)

The time complexity for this solution is O(n x logk). This is because we are traversing the entire array which takes O(n) time. 
Inside the traversal loop, we are removing the elements from the priority queue. 
Removing an element from the priority queue takes O(logk) time since the size of the priority queue is O(k). Hence the overall time complexity becomes O(n x logk).

Space Complexity: O(k)

The space complexity for this solution is O(k) as we have created a priority queue of size k+1. 
Though we are adding and removing the elements from it still we have created it only once and the same priority queue is used for the entire procedure. Thus the space complexity is O(k).*/