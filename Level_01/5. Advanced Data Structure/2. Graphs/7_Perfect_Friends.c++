/*1. You are given a number n (representing the number of students). Each student will have an id 
     from 0 to n - 1.
2. You are given a number k (representing the number of clubs)
3. In the next k lines, two numbers are given separated by a space. The numbers are ids of 
     students belonging to same club.
4. You have to find in how many ways can we select a pair of students such that both students are 
     from different clubs.

Constraints
None

Format
Input
Input has been managed for you

Output
Check the sample output

Example
Sample Input
7
5
0 1
2 3
4 5
5 6
4 6

Sample Output
16
*/

#include<bits/stdc++.h>
using namespace std;
  
   class Edge {
       public:
          int src=0;
          int nbr=0;
      Edge(int src, int nbr){
         this->src = src;
         this->nbr = nbr;
      }
   };
   
void getCmp(vector<vector<Edge>> graph, vector<bool> &vis , int src, vector<int>&scomp){
    vis[src] = true;
    scomp.push_back(src);
    for(Edge ed : graph[src]){
        if(!vis[ed.nbr]){
           getCmp(graph , vis , ed.nbr , scomp);
        }
    }
 }
   
int main(){
      int n;
      cin>>n;   
      int k;
      cin>>k;   
      vector<vector<Edge>> graph(n, vector<Edge>());;   
      for(int e = 0; e < k; e++){
         int v1 ;
         int v2 ;
         cin>>v1>>v2;
         graph[v1].push_back(Edge(v1, v2));
         graph[v2].push_back(Edge(v2, v1));
        }
      vector<bool> vis(n , false);
      vector<vector<int>> comps;
      for(int i = 0;i < n;i++){
          if(vis[i] == false){
              vector<int> scomp;
              getCmp(graph, vis, i, scomp);
              comps.push_back(scomp);
          }
      }
      int pair = 0;
      for(int i = 0;i < comps.size();i++){
         for(int j = i+1;j < comps.size();j++){  
          int sum = comps[i].size()*comps[j].size();
          pair += sum;
        }
      }
     cout<<pair;      
}

/*Time Complexity:O(V+E) 

Because the DFS approach has been used.


Space Complexity : O(v)

O(v) for visited array
*/