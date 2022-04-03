/*1. You are given a graph, a src vertex and a destination vertex.
2. You are required to find if a path exists between src and dest. If it does, print true 
     otherwise print false.

Constraints
None

Format
Input
Input has been managed for you

Output
true if path exists, false otherwise

Example
Sample Input
7
8
0 1 10
1 2 10
2 3 10
0 3 10
3 4 10
4 5 10
5 6 10
4 6 10
0
6

Sample Output
true*/

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
   
   bool hasPath(vector<Edge>graph[] ,int  src , int dest , vector<bool> vis){
        if(src == dest)
            return true;
        vis[src] = true;
        for(Edge ed : graph[src]){
            if(vis[ed.nbr] == false && hasPath(graph , ed.nbr , dest , vis))
               return true;
        }
       return false;
   }
   
   int main(){
      int vtces;
      cin>>vtces;
      vector<Edge>graph[vtces];
      int edges;
      cin>>edges;
      for(int i = 0; i < edges; i++){
         int v1 ;
         int v2 ;
         int wt ;
         cin>>v1>>v2>>wt;
         graph[v1].push_back( Edge(v1, v2, wt));
         graph[v2].push_back( Edge(v2, v1, wt));
      }
      int src;
      cin>>src;
      int dest;
      cin>>dest;
      vector<bool> vis(vtces , false);
      if(hasPath(graph , src , dest , vis)){
        cout<<"true"<<endl;  
      }else{
        cout<<"false"<<endl;  
          
      }
    }

/*Time Complexity: O(V+E)

Where V is the number of vertices and E is the number of edges. In the worst case, all the vertices and all the edges will be travelled.
The time complexity of the while loop (k log(k)).Which sum up to O(n log(k)).

Space Complexity: O(V)

It will be the height of the recursion stack, which can be O(V) at max.*/