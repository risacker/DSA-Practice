/*1. You are given a partially written BST class. 
2. You are given a value. You are required to print all pair of nodes which add up to the given value. 
Make sure all pairs print the smaller value first and avoid duplicacies. Make sure to print the pairs in increasing order. 
3. Input and Output is managed for you.

Constraints
None

Format
Input
Input is managed for you

Output
"smaller node" "larger node"
.. all pairs that add to target on separate lines

Example
Sample Input
21
50 25 12 n n 37 30 n n n 75 62 60 n n 70 n n 87 n n
100

Sample Output
25 75
30 70
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Node{
public:
  int data;
  Node * left = nullptr;  
  Node * right = nullptr;
  Node (int data)
  {
      this->data=data;
  }
};

class Pair{
    Node *node = nullptr;
    int state=0;

    Pair(Node *node, int state) {
      this->node = node;
      this->state = state;
    }
};

Node* construct(vector<int> & arr) {
  Node* root = new Node(arr[0]);
  pair<Node*, int> p = {root, 1};

  stack<pair<Node*, int>> st;
  st.push(p);

  int idx = 1;
  while (!st.empty()) {
    if (st.top().second == 1) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->left = new Node(arr[idx]);
        pair<Node*, int> lp = {st.top().first->left, 1};
        st.push(lp);
      }
      else {
        st.top().first->left = nullptr;
      }
      idx++;
    }
    else if (st.top().second == 2) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->right = new Node(arr[idx]);
        pair<Node*, int> rp = {st.top().first->right, 1};
        st.push(rp);
      } else {
        st.top().first->right = nullptr;
      }
      idx++;
    }
    else {
      st.pop();
    }

  }
  return root;
}

 bool find(Node *node, int data)
{
    if (node == nullptr){
        return false;
    }    
    
    if(node->data > data){
        return find(node->left, data);
    }
    else if(node->data < data){
        return find(node->right, data);
    }
    else {
        return true;
    }
}


   void travelAndPrint(Node * root , Node * node , int tar){
      
      if(node == nullptr){
          return;
      }
      travelAndPrint(root,node->left,tar);
      int comp = tar - node->data;
      if(node->data<comp){
      if(find(root,comp)==true){
          cout<<node->data << " " << comp <<endl;
      }
      }
      travelAndPrint(root,node->right,tar);
      
  }

  int main() {
    int n;
    cin>>n;
    vector<int> arr(n,0);
    
    for(int i = 0; i < n; i++) {
        string tmp;
        cin>>tmp;
      if (tmp=="n") {
        arr[i] = -1;
      } else {
        arr[i] = stoi(tmp);
      }
    }

    int k1;
    cin>>k1;

    Node* root = construct(arr);
    travelAndPrint(root,root,k1);
 }

/*Time Complexity: O(nlogn)

The time complexity for this approach is O(nlogn) where n is the time to traverse the tree and logn for calling find() function for every node.

Space Complexity: O(logn)

The space complexity for the function is proportional to the height of the tree due to the recursion stack.*/