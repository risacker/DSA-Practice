/*1. You are given a graph.
2. You are required to find and print if the graph is connected (there is a path from 
     every vertex to every other).

Constraints
None

Format
Input
Input has been managed for you

Output
true if the graph is connected, false otherwise

Example
Sample Input
7
5
0 1 10
2 3 10
4 5 10
5 6 10
4 6 10

Sample Output
false
*/

#include<bits/stdc++.h>
using namespace std;
   class Edge {
       public:
          int src;
          int nbr;
          int wt;
      Edge(int src, int nbr, int wt){
         this->src = src;
         this->nbr = nbr;
         this->wt = wt;
      }
   };
   
    void dfs(vector<Edge>graph[] , int src , vector<bool>&visited){
       visited[src] = true;
       for(Edge ed : graph[src]){
           if(visited[ed.nbr] == true)continue;
           dfs(graph,ed.nbr,visited);
       }
    }
 
   int main(){
      int vtces;
      cin>>vtces;
      vector<Edge>graph[vtces];
      int edges;
      cin>>edges;
      for(int i = 0; i < edges; i++){
         int v1;
         int v2;
         int wt;
         cin>>v1>>v2>>wt;
         graph[v1].push_back(Edge(v1, v2, wt));
         graph[v2].push_back(Edge(v2, v1, wt));
      }
      int src;
      cin>>src;
      int dest;
      cin>>dest;
      vector<bool> vis(vtces , false);
      dfs(graph,0,vis);
      for(int i = 0 ; i<vtces ; i++){
          if(!vis[i]){
              cout<<"false";
              return 0;
          }
      }
      cout<<"true";
}

/*Time complexity: O((v+e)). 

Space complexity: O(v)*/