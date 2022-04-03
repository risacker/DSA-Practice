/*1. You are given a graph.
2. You are required to find and print if the graph is cyclic.

Constraints
None

Format
Input
Input has been managed for you

Output
true if the graph is cyclic, false otherwise

Example
Sample Input
7
6
0 1 10
1 2 10
2 3 10
3 4 10
4 5 10
5 6 10

Sample Output
false
*/

#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;

class Edge{
public:
  int src = 0;
  int nbr = 0;
  Edge(int src, int nbr){
    this->src = src; 
    this->nbr = nbr;
  }
};

class Pair{
public:
  int src = 0;
  string psf = "";
  Pair(int src, string psf){
    this->src = src;
    this->psf = psf; 
  }
}; 
  
bool cycle(vector<vector<Edge>> graph,int src,vector<bool> &visited){
  queue<Pair> q;  
  q.push(Pair(src,to_string(src) + ""));  
  while(q.size() != 0){      
    Pair rem = q.front();
    q.pop();
    if(visited[rem.src] == true){  
        return true;
    }
    visited[rem.src] = true;
    for(Edge e: graph[rem.src]){
        if(visited[e.nbr] == false){
            q.push(Pair(e.nbr,rem.psf+to_string(e.nbr)));
        }
      }
  }
  return false;
} 

int main() {                                                                        
  int vtces;
  cin>>vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());
  int edges;
  cin>>edges;
  for (int i = 0; i < edges; i++ ) {
    int u, v, w; 
    cin>>u>>v>>w;
    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));
  } 

  vector<bool> visited(vtces,false);
   for(int i = 0;i < vtces;i++){
    if(visited[i] == false){
        bool ans = cycle(graph,i,visited);
        if(ans){
            cout<<"true";
            return 0;
        }
      }  
    }  
    cout<<"false";
    return 0;
}  

/*Time Complexity: O(N + E)

We are doing a simple BFS traversal of the graph. Hence the time complexity will be O(N + E) where N = number of vertices and E = number of edges.

Space Complexity: O(n)

We are building a visited array and a parent array of size equal to the number of vertices. 
Also, we are taking the queue data structure to perform BFS traversal, which will store at max n nodes. Hence, the total space complexity will be O(n + n + n) = O(n) only.*/