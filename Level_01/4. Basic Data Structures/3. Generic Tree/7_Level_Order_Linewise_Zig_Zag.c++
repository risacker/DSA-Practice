/* 1. You are given a partially written GenericTree class.
2. You are required to complete the body of levelorderLineWiseZZ function. The function is expected to visit every node in "levelorder fashion" but in a zig-zag manner i.e. 1st level should be visited from left to right, 2nd level should be visited from right to left and so on. All nodes on same level should be separated by a space. Different levels should be on separate lines. Please check the question video for more details.
3. Input is managed for you. 
                                                  
Constraints
None

Format
Input
Input is managed for you

Output
All nodes on the same level should be separated by a space.
1st level should be visited left to right, 2nd from right to left and so on alternately.
All levels on separate lines starting from top to bottom.

Example
Sample Input
24
10 20 50 -1 60 -1 -1 30 70 -1 80 110 -1 120 -1 -1 90 -1 -1 40 100 -1 -1 -1

Sample Output
10 
40 30 20 
50 60 70 80 90 100 
120 110*/

#include<bits/stdc++.h>
#include<climits>
using namespace std;

class Node
{
public:
  int data = 0;
  vector<Node *> children;
  Node(int data)
  {
    this->data = data;
  }
};

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

void levelOderZigZag(Node *node)
{
  if (node == NULL || node->children.size() == 0)
    return;
  stack<Node *> st, st1;
  st.push(node);
  int count = 1;
  while (!st.empty())
  {
    Node *nd = st.top();
    st.pop();
    cout << nd->data << " ";
    if ((count %2) == 1)
    {
      for (Node *child : nd->children)
        st1.push(child);
    }
    else
    {
      for (int i = nd->children.size() - 1; i >= 0; i--)
        st1.push(nd->children[i]);
    }
    if (st.size() == 0)
    {
      swap(st, st1);
      cout << endl;
      count++;
    }
  }
}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    Node * root = constructor01(arr);
    levelOderZigZag(root);
}

int main()
{
    solve();
    return 0;
}

/*Time Complexity: O(n)

If you notice carefully we are just inserting one node in a stack and then popping it. 
So for every node, we are performing constant time operations and hence we will have n*O(1) = O(n) time complexity.

Space Complexity: O(n)*/