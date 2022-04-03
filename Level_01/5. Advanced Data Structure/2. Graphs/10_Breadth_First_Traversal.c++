/*1. You are given a graph, and a src vertex.
2. You are required to do a breadth first traversal and print which vertex is reached via which path, 
     starting from the src.

Note -> for output, check the sample output and question video.

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
8
0 1 10
1 2 10
2 3 10
0 3 10
3 4 10
4 5 10
5 6 10
4 6 10
2

Sample Output
2@2
1@21
3@23
0@210
4@234
5@2345
6@2346*/

#include <iostream>
#include <vector>
#include <queue>
#include<string>
using namespace std;

class Edge{
public:
  int src = 0;
  int nbr = 0;
  Edge(int src, int nbr)
  {
    this->src = src; 
    this->nbr = nbr;
  }
};

class Pair{
public:
  int src = 0;
  string psf="";
  Pair(int src, string psf)
  {
    this->src = src;
    this->psf = psf; 
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
  int src; 
  cin>>src;
  vector<bool> visited(vtces,false);
  queue<Pair> q;  
  q.push(Pair(src,to_string(src)+""));  
  while(q.size() != 0){    
    Pair rem = q.front();
    q.pop();
      if(visited[rem.src] == true){  
          continue;
      }
      visited[rem.src] = true;
      cout<<rem.src<<"@"<<rem.psf<<endl;
      for(Edge e: graph[rem.src]){
          if(visited[e.nbr] == false){
              q.push(Pair(e.nbr,rem.psf+to_string(e.nbr)));
          }
      }
  }
  return 0;
}

/*Time Complexity:-

The adding and removing of elements from the queue takes O(1) time. 
Since we are traversing every vertex of the graph to print its breadth first traversal, the time taken will be O(n).

Space Complexity: O(n)

Since we have used a queue data structure, the space complexity of the above method is O(n)*/