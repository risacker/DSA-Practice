/*1. You are given a graph, representing people and their connectivity.
2. You are also given a src person (who got infected) and time t.
3. You are required to find how many people will get infected in time t, if the infection spreads to neighbors of infected person in 1 unit of time.

Constraints
None

Format
Input
Input has been managed for you

Output
count of people infected by time t

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
6
3

Sample Output
4
*/

#include <iostream>
#include <vector>
#include <queue>
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
  int time = 0;
  Pair(int src, int time)
  {
    this->src = src;
    this->time = time; 
  }
}; 

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
  int src,t; 
  cin>>src;
  cin>>t; 
  vector<bool> visited(vtces,false);
  queue<Pair> q;  
  q.push(Pair(src,1));  
  int count = 0; 
  while(q.size() != 0){    
    Pair rem = q.front();
    q.pop(); 
      if(visited[rem.src] == true){  
          continue;
      }
      visited[rem.src] = true;
      if(rem.time > t){
          break;
      }
      count++;
      for(Edge e: graph[rem.src]){
          if(visited[e.nbr] == false){
              q.push(Pair(e.nbr,rem.time + 1));
          }
      }
  }
  cout<<count;
  return 0;
}

/*Time Complexity: O(N + E)

We are simply doing a BFS traversal, hence the time complexity will be O(N + E) where N = number of vertices in the graph and E = number of edges in the graph.

Space Complexity: O(N)

To perform BFS, we use queue data structure, which will take O(N) auxiliary space. Please note that we are not taking into account the space taken to build the adjacency list, as it was given to us as an input.*/