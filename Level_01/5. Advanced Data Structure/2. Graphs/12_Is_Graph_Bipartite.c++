/*1. You are given a graph.
2. You are required to find and print if the graph is bipartite.

Note -> A graph is called bipartite if it is possible to split it's vertices in two sets of mutually 
exclusive and exhaustive vertices such that all edges are across sets.

Constraints
None

Format
Input
Input has been managed for you

Output
true if the graph is bipartite, false otherwise

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

Sample Output
false*/

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
  int level = 0;
  Pair(int src, string psf,int level){
    this->src = src;
    this->psf = psf;
    this->level = level;
  }
};
  
bool bipartite(vector<vector<Edge>> graph,int src,vector<int> &visited){
  queue<Pair> q;  
  q.push(Pair(src,to_string(src) + "", 0));  
  while(q.size() != 0){    
    Pair rem = q.front();
    q.pop();   
    if(visited[rem.src] != -1){ 
      if(visited[rem.src] != rem.level){  
           return false;
        }
    }
    else{
          visited[rem.src] = rem.level;
    }
      for(Edge e: graph[rem.src]){
          if(visited[e.nbr] == -1){
              q.push(Pair(e.nbr, rem.psf+to_string(e.nbr), rem.level+1));
          }
      }
    }
  return true;
} 

int main() {                                                                        
  int vtces;
  cin>>vtces;
  vector<vector<Edge>> graph(vtces, vector<Edge>());
  int edges;
  cin>>edges;
  for(int i = 0; i < edges; i++ ) {
    int u, v, w; 
    cin>>u>>v>>w;
    graph[u].push_back(Edge(u, v));
    graph[v].push_back(Edge(v, u));
  } 
  
  vector<int> visited(vtces,-1);
  for(int i = 0;i < vtces;i++){
    if(visited[i] == -1){
        bool ans = bipartite(graph,i,visited);
        if(ans == false){
            cout<<"false";
                return 0;
        }
      }  
    } 
    cout<<"true";
    return 0;
}

/*Time Complexity: O(N + E)

We are simply doing a BFS traversal of the entire graph, which will take O(N + E) time, where N = number of vertices, and E = number of edges.

Space Complexity: O(N)

We are using a queue data structure for the BFS traversal, which will store at max N vertices. 
Hence, the space complexity is O(N). Please note that we are not taking into account the space taken to build the adjacency list, as it was given to us as an input.*/