/*1. You are given a graph, and a source vertex.
2. You are required to do a iterative depth first traversal and print which vertex is reached via which 
     path, starting from the source.

Note -> For output, check the sample output and question video. Iterative depth first traversal 
               should mimic "Reverse preorder" i.e. nbr with highest value should be visited first and 
               should be printed on the way down in recursion.

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
3@23
4@234
6@2346
5@23465
0@230
1@2301
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Edge{  
public:
  int src = 0; 
  int nbr = 0;
  int wt = 0; 
  Edge(int src, int nbr,int wt){
    this->src = src; 
    this->nbr = nbr; 
    this->wt = wt; 
  }
};

class Pair{
    public:
    int src = 0;
    string psf = "";
    Pair(int src,string psf){
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
    graph[u].push_back(Edge(u, v, w));    
    graph[v].push_back(Edge(v, u, w));    
  }   
  int src;
  cin>>src; 
  vector<bool>visited(vtces,false);
  stack<Pair> st; 
  string s = to_string(src);
  st.push(Pair(src,s));
  while(st.size() != 0){
      Pair rem = st.top();
      st.pop();
      if(visited[rem.src] == true){
          continue;
      }
      visited[rem.src] = true;
      cout<<rem.src<<"@"<<rem.psf<<endl;
      for(Edge e: graph[rem.src]){
             string s1 = to_string(e.nbr);
          st.push(Pair(e.nbr,rem.psf + s1));
      }
  }
  return 0;
}

/*Time Complexity: O(N + E)

We have just replaced the queue data structure with stack, and the rest of the code remains the same. Hence, the time complexity will also remain O(N + E) where N = number of vertices and E = number of edges.

Space Complexity: O(N)

We are using a stack data structure, which will store at max N nodes. Also, we are using a visited array of size N. Hence the total space complexity is O(N).*/