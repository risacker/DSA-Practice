/*1. You are given a partially written GenericTree class. 
2. You are required to complete the body of lca function. The function is expected to return the lowest common ancestor of two data values that are passed to it.
3. Input and Output is managed for you.

Constraints
None

Format
Input
Input is managed for you

Output
Output is managed for you

Example
Sample Input
24
10 20 50 -1 60 -1 -1 30 70 -1 80 110 -1 120 -1 -1 90 -1 -1 40 100 -1 -1 -1
120
80

Sample Output
80*/

#include<bits/stdc++.h>
#include<climits>
using namespace std;

class Node{
public:
  int data = 0;
  vector<Node *> children;
  Node(int data)
  {
    this->data = data;
  }
};

void display(Node *node)
{
  string s = "";
  s += to_string(node->data) + " Child: ";
  for (Node *child : node->children)
  {
    s += to_string(child->data) + ", ";
  }
  cout << s << "." << endl;
  for (Node *child : node->children)
  {
    display(child);
  }
}

Node *constructor01(vector<int> &arr)
{
  if (arr.size() == 0)
    return NULL;
  vector<Node *> stack;
  stack.push_back(new Node(arr[0]));
  Node *root = stack[0];
  for (int i = 1; i < arr.size(); i++)
  {
    if (arr[i] != -1)
    {
      Node *node = stack.back();
      Node *nnode = new Node(arr[i]);
      node->children.push_back(nnode);
      stack.push_back(nnode);
    }
    else
      stack.pop_back();
  }
  return root;
}

vector<int> *rootNodeToPath(Node *node, int data)
{
  if (node->data == data)
  {
    vector<int> *base = new vector<int>();
    base->push_back(data);
    return base;
  }
  vector<int> *ans = new vector<int>();
  for (Node *child : node->children)
  {
    vector<int> *recAns = rootNodeToPath(child, data);
    if (recAns->size() > 0)
    {
      recAns->push_back(node->data);
      return recAns;
    }
  }
  return ans;
}

int lca(Node *node, int data1, int data2)
{
  vector<int> onePath = *rootNodeToPath(node, data1);
  vector<int> twoPath = *rootNodeToPath(node, data2);
  int i = onePath.size() - 1;
  int j = twoPath.size() - 1;
  bool flag = false;
  while (i >= 0 && j >= 0 && onePath[i] == twoPath[j])
  {
    flag = true;
    i--;
    j--;
  }
  return onePath[i+1];
}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i = 0; i < arr.size(); i++)
    {
        cin>>arr[i];
    } 
    int data1;
    cin>>data1;
    int data2;
    cin>>data2;
    Node *root = constructor01(arr);
    int Lca = lca(root,data1,data2);
    cout<<Lca<<endl;
}

int main()
{
    solve();
    return 0;
}

/*Time Complexity: O(n)

Finding the node in the entire tree to get it's node to the root path is an O(n) task. 
Then, just traversing the node-to-root path (arrays) takes O(d) where d = depth of node. 
In the worst case, d can be equal to n, hence total time complexity will be O(n) only.

Space Complexity: O(n)

We are storing node-to-root paths in arraylists. This will take O(n) auxiliary space.*/