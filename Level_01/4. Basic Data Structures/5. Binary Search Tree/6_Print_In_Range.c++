/*1. You are given a partially written BST class.
2. You are required to complete the body of pir function. "pir" function is expected to print all nodes between d1 and d2 (inclusive and in increasing order).
3. Input and Output is managed for you. 

Note -> Please watch the question video for clarity.

Constraints
None

Format
Input
Input is managed for you

Output
Output is managed for you

Example
Sample Input
21
50 25 12 n n 37 30 n n n 75 62 60 n n 70 n n 87 n n
12
65

Sample Output
12
25
30
37
50
60
62
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Node{
public:
  int data;
  Node* left = nullptr;  
  Node* right = nullptr;
  Node (int data)
  {
      this->data=data;
  }
};

class Pair{
    Node* node = nullptr;
    int state=0;

    Pair(Node* node, int state) {
      this->node = node;
      this->state = state;
    }
};

void pir(Node* node, int d1, int d2)
{
    if(node == NULL) return;
    if(d1 < node->data && d2< node->data){
        pir(node->left,d1,d2);
    }else if(d1>node->data && d2>node->data){
        pir(node->right,d1,d2);
    }else{
        pir(node->left,d1,d2);
        cout<<node->data<<endl;
        pir(node->right,d1,d2);
    }
}

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
    int k2;
    cin>>k2;

    Node* root = construct(arr);
    pir(root,k1,k2);
 }

/*Time Complexity: O(logn)

The time complexity for the function is proportional to the height of the binary search tree as for every call we are neglecting one of the subtrees.

Space Complexity: O(logn)

The space complexity for the function is proportional to the height of the tree due to the recursion stack.*/