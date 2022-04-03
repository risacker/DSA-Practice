/*1. You are given a graph and a source vertex. The vertices represent cities and the edges represent 
    distance in kms.
2. You are required to find the shortest path to each city (in terms of kms) from the source city along 
    with the total distance on path from source to destinations.

Note -> For output, check the sample output and question video.

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
9
0 1 10
1 2 10
2 3 10
0 3 40
3 4 2
4 5 3
5 6 3
4 6 8
2 5 5
0

Sample Output
0 via 0 @ 0
1 via 01 @ 10
2 via 012 @ 20
5 via 0125 @ 25
4 via 01254 @ 28
6 via 01256 @ 28
3 via 012543 @ 30
*/

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

class Edge{  
public:
  int src = 0; 
  int nbr = 0;
  int wt = 0;

  Edge(int src, int nbr, int wt){
    this->src = src; 
    this->nbr = nbr;
    this->wt = wt;
  }
};

class Pair {
public:
  int src = 0;
  string psf = ""; 
  int wt = 0;
  Pair(int src, string psf, int wt){
    this->src = src; 
    this->psf = psf; 
    this->wt = wt; 
  }
};
 
struct comp{
    public :
    bool operator()(Pair const& a,Pair const& b) const{
        return a.wt >= b.wt;
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
    graph[u].push_back(Edge(u, v, w));
    graph[v].push_back(Edge(v, u, w));

  } 
  int src;  
  cin>>src;  
  stringstream ss;
  ss<<src; 
  string s;
  ss>>s;  
  vector<bool> visited(vtces,false);
  priority_queue<Pair,vector<Pair>,comp> q; 
  q.push(Pair(src,s, 0));    
  while(!q.empty()){   
      Pair rem = q.top();
      q.pop();
      if(visited[rem.src] == true){
          continue;  
      }
      visited[rem.src] = true;
      cout<<rem.src<<" via "<<rem.psf<<" @ "<<rem.wt<<endl;
      for(Edge e: graph[rem.src]){
          if(visited[e.nbr] == false){
              stringstream ss1;
              ss1<<e.nbr;
              string s1;
              ss1>>s1;
              q.push(Pair(e.nbr,rem.psf+s1,e.wt+rem.wt));   
          }
      }
  }
  return 0;
}

/*Time Complexity: O(E + V logV)

This is an interesting analysis. The time complexity of Dijkstra's algorithm will be O(E + V logV) where V = number of vertices and E = number of edges. 
This is because, we are iterating over all the edges once during the entire run of the algorithm In each iteration, we are popping one node and pushing the unvisited neighbour nodes. 
Since the priority queue can contain all the vertices, the push or pop operation will be O(log V). Hence the total time complexity will be O(E) + O(V) * O(log V) = O(E + V log V). 
Note: You can argue that we might be having multiple Pairs having the same node's value. So, the maximum size of the priority queue will be not O(N) but O(E). 
But, even if you replace log V with Log E (cost of one push/pop operation), then there will be no difference in the time complexity as: O(E + VlogE) = O(E + Vlog(V^2)) = O(E + 2V logV) = O(E + V logV) only.


Space Complexity: O(N)

We are taking a priority queue of Pair nodes. Hence, the space complexity will be O(N) where N = maximum Pair nodes in the queue, which is equivalent to O(V).*/