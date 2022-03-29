/*1. You are given a number n1, representing the size of array a1. 
2. You are given n1 numbers, representing elements of array a1. 
3. You are given a number n2, representing the size of array a2. 
4. You are given n2 numbers, representing elements of array a2. 
5. You are required to find the intersection of a1 and a2. To get an idea check the example below: 
if a1 -> 1 1 2 2 2 3 5 and a2 -> 1 1 1 2 2 4 5 intersection is -> 1 1 2 2 5 
Note -> Don't assume the arrays to be sorted. 

Constraints
1 <= n1, n2 <= 100 0 <= a1[i], a2[i] < 10 Time complexity should be O(n)

Format
Input
A number n1 n1 number of elements line separated A number n2 n2 number of elements line separated

Output
All relevant elements of intersection in separate lines The elements of intersection should be printed in order of their occurence in a2.

Example
Sample Input
7
1
1
2
2
2
3
5
7
1
1
1
2
2
4
5

Sample Output
1
1
2
2
5*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
	int n,m;
	cin>>n;
	int arr1[n];
	unordered_map<int,int> mp;
	for(int i=0;i<n;i++){
		cin >> arr1[i];
		mp[arr1[i]]++;
	}
	cin>>m;
	int arr2[m];
	for(int i=0;i<m;i++){
		cin>>arr2[i];
		if(mp.find(arr2[i])!=mp.end() && mp[arr2[i]]!=0){
		    cout<<arr2[i]<<endl;
		    mp[arr2[i]]--;
		}
	}
}

/*TIME COMPLEXITY- O(n)

SPACE COMPLEXITY- O(n) 

where n= number of entities in the Hashmap.*/