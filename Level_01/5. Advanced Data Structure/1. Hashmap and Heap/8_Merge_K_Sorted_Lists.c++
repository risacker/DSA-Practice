/*1. You are given a list of lists, where each list is sorted.
2. You are required to complete the body of mergeKSortedLists function. The function is expected to merge k sorted lists to create one sorted list.

Constraints
Space complextiy = O(k)
Time complexity = nlogk
where k is the number of lists and n is number of elements across all lists.

Format
Input
Input is managed for you

Output
Output is managed for you

Example
Sample Input
4
5
10 20 30 40 50
7
5 7 9 11 19 55 57
3
1 2 3
2
32 39

Sample Output
1 2 3 5 7 9 10 11 19 20 30 32 39 40 50 55 57 */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int, int> > ppi;
 
vector<int>mergeKSortedLists(vector<vector<int>>&lists){    
    vector<int> rv; 
    priority_queue<ppi, vector<ppi>, greater<ppi> > pq;
 
    for (int i = 0; i < lists.size(); i++)
        pq.push({ lists[i][0], { i, 0 } });
    while (pq.empty() == false){
        ppi curr = pq.top();
        pq.pop();
        int arrayNumber = curr.second.first;
        int idx = curr.second.second;
        rv.push_back(curr.first);
        if (idx + 1 < lists[arrayNumber].size())
            pq.push({ lists[arrayNumber][idx + 1], { arrayNumber, idx + 1 } });
    }
    return rv;
}

int main(){
  int k;
  cin>>k;
  vector<vector<int>>lists;
  for(int i = 0; i < k; i++){
    vector<int>list;
    int n;
    cin>>n;
    for(int j = 0; j < n; j++){
      int data;
      cin>>data;
      list.push_back(data);
    }
    lists.push_back(list);
  }

  vector<int> mlist = mergeKSortedLists(lists);
  for (int val : mlist) {
    cout<<val<<" ";
  }
  cout<<endl;
  return 0;
}

/*Time Complexity: O(nlogn)

The time complexity for this approach is O(nlogn) where n is the time to traverse the tree and logn for calling find() function for every node.

Space Complexity:-

The space complexity for the function is proportional to the height of the tree due to the recursion stack.*/