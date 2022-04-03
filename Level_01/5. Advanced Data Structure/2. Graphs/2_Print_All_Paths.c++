/*1. You are given a graph, a source vertex and a destination vertex. 
2. You are required to find and print all paths between source and destination. Print them in lexicographical order. 
E.g. Check the following paths 012546 01256 032546 03256 The lexicographically smaller path is printed first.

Constraints
None

Format
Input
Input has been managed for you

Output
Check sample output

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
0123456
012346
03456
0346*/

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
   
    void printPath(vector<Edge> graph[] , int src , int des , vector<bool>vis ,string path){
        if(src == des){
            cout<<path<<endl;
            return;
        }
        vis[src] = true;
        for(Edge ed : graph[src]){
            if(vis[ed.nbr] == false){
                string ans  = to_string(ed.nbr);
                printPath(graph , ed.nbr , des , vis , path+ans);
            }
        }
        vis[src] = false;
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
         graph[v1].push_back( Edge(v1, v2, wt));
         graph[v2].push_back( Edge(v2, v1, wt));
      }
      int src;
      cin>>src;
      int dest;
      cin>>dest;
      vector<bool> vis(vtces , false);
      printPath(graph , src , dest , vis ,to_string(src));
    }  

/*Time Complexity: O(V+E)

Where V is the number of vertices and E is the number of edges. In the worst case, all the vertices and all the edges will be travelled. 
SThe time complexity of the while loop (k log(k)).Which sum up to O(n log(k)).


Space Complexity: O(V)

It will be the height of the recursion stack, which can be O(V) at max*/