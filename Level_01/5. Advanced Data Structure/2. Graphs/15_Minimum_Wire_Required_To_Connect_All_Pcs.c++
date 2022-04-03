/*1. You are given a graph and a source vertex. The vertices represent computers and the edges 
     represent length of LAN wire required to connect them.
2. You are required to find the minimum length of wire required to connect all PCs over a network. 
     Print the output in terms of which all PCs need to be connected, and the length of wire between 
     them.

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
8
0 1 10
1 2 10
2 3 10
0 3 40
3 4 2
4 5 3
5 6 3
4 6 8

Sample Output
[1-0@10]
[2-1@10]
[3-2@10]
[4-3@2]
[5-4@3]
[6-5@3]*/

#include <iostream>
#include <vector>
#include <queue>
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
  int asrc = 0;
  int wt = 0;
  Pair(int src, int asrc, int wt){
    this->src = src; 
    this->asrc = asrc; 
    this->wt = wt; 
  }
};
 
struct comp{
    public :
    bool operator()(Pair const& a,Pair const& b) const{
        return a.wt > b.wt;
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
  
 priority_queue<Pair,vector<Pair>,comp> q;
 q.push(Pair(0, -1, 0));
 vector<bool> visited(vtces,false);
  while(!q.empty()){   
      Pair rem = q.top(); 
      q.pop();
      if(visited[rem.src] == true){
          continue;  
      }
      visited[rem.src] = true;
      if(rem.asrc != -1)
      cout<< "["<<rem.src<<"-"<<rem.asrc<<"@"<<rem.wt<<"]"<<endl;
      for(Edge e: graph[rem.src]){
          if(visited[e.nbr] == false){
              q.push(Pair(e.nbr,rem.src,e.wt));
          }
      }
  }
  return 0;
}

/*Time complexity: O((v+e)logv). 

Space complexity: O(v+e)*/