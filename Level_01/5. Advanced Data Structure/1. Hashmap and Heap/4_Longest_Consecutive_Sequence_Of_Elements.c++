/*1. You are given a number n, representing the size of array a.
2. You are given n numbers, representing elements of array a.
3. You are required to print the longest sequence of consecutive elements in the array (ignoring duplicates).

Note -> In case there are two sequences of equal length (and they are also the longest), then print the one for which the starting point of which occurs first in the array.

Constraints
1 <= n <= 30
0 <= n1, n2, .. n elements <= 15

Format
Input
A number n
n1
n2
.. n number of elements

Output
Elements of longest sequence of consecutive elements of array in separate lines (ignoring duplicates)

Example
Sample Input
17
12
5
1
2
10
2
13
7
11
8
9
11
8
9
5
6
11

Sample Output
5
6
7
8
9
10
11
12
13*/

#include<bits/stdc++.h>
using namespace std;

void longestConsecutive(vector<int> &num){
    unordered_map<int,bool>mp;
    for (int i = 0;i < num.size();i++){
        mp[num[i]] = true;
    }
    for(int i = 0;i < num.size();i++){
        if(mp.find(num[i]-1) != mp.end()){
            mp[num[i]] = false;
        }
    }  
      int msp = 0;
      int ml = 0;
      for(int val : num){
         if(mp[val] == true){
            int tsp = val;
            int tl = 1;
            while(mp.find(tsp + tl) != mp.end()){
               tl++;
            }
            if(tl > ml){
               ml = tl;
               msp = tsp;
            }
         }
      }
      for(int i = 0; i < ml; i++){
         cout<<msp + i<<endl;
      }     
    }

int main(){
  vector<int>arr;
  int n;
  cin>>n;
  for(int i = 0 ; i < n; i++) {
    int data;
    cin>>data;
    arr.push_back(data);
  }
    longestConsecutive(arr);
}

/*TIME COMPLEXITY- O(n)

Since the hashmap is traversed once therefore the time complexity is linear.

SPACE COMPLEXITY- O(n) 

where n = number of entities in the Hashmap.*/