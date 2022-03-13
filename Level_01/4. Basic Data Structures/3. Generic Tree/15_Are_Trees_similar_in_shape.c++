/*1. You are given a partially written GenericTree class.
2. You are required to complete the body of areSimilar function. The function is expected to check if the two trees passed to it are similar in shape or not.
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
24
1 2 5 -1 6 -1 -1 3 7 -1 8 11 -1 12 -1 -1 9 -1 -1 4 10 -1 -1 -1

Sample Output
true*/

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

Node *constructor01(vector<int>arr)
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

int sizeRec(Node *node)
{
  int size = 0;
  for (Node *child : node->children)
  {
    size += sizeRec(child);
  }
  return size + 1;
}

int maxEle(Node *node)
{
  int OverMax = node->data;
  for (Node *child : node->children)
  {
    OverMax = max(OverMax, maxEle(child));
  }
  return OverMax;
}

int height(Node *node)
{
  int ht = 0;
  for (Node *child : node->children)
  {
    ht = max(ht, height(child));
  }
  return ht + 1;
}

bool areSimilar(Node *n1, Node *n2) 
{   
    if(n1->children.size() != n2->children.size())
    {
        return false;
    }   
    for(int i = 0; i < n1->children.size(); i++)
    {
      Node *c1 = n1->children[i];
      Node *c2 = n2->children[i]; 
      if(areSimilar(c1,c2) == false)
      {
          return false;
      }
    }
    return true;
}

void solve()
{
    int n1;
    cin>>n1;
    vector<int>arr1(n1,0);
    for(int i = 0; i < n1; i++)
    {
        cin>>arr1[i];
    }
     Node *root1 = constructor01(arr1);   
    int n2;
    cin>>n2;
    vector<int>arr2(n2,0);
    for(int i = 0; i < n2; i++)
    {
        cin>>arr2[i];
    }
    Node *root2 = constructor01(arr2);  
    bool similar = areSimilar(root1, root2);
    if(similar == true)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
}

int main()
{
    solve();
    return 0;
}                        

/*Time Complexity: O(n)

The time complexity will be O(n) as we have traversed every node of both the trees if they are of the same shape.

Space Complexity:-

The space complexity is O(1) as we have not used any extra data structure. 
As usual if we consider the recursion space then the space complexity will be O(logn) as the max height of the stack at any point will be the same as the height of the tree i.e. O(logn).*/