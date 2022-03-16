/*1. You are given a partially written BinaryTree class.
2. You are required to complete the body of iterativePrePostInTraversal function. 
The function is expected to print pre order, in order and post order of the tree in separate lines (first pre, then in and finally post order). All elements in an order must be separated by a space.
3. Input is managed for you.

Constraints
None

Format
Input
Input is managed for you

Output
pre order (elements separated by space)
in order (elements separated by space)
post order (elements separated by space)

Example
Sample Input
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n

Sample Output
50 25 12 37 30 75 62 70 87 
12 25 30 37 50 62 70 75 87 
12 30 37 25 70 62 87 75 50*/

#include<iostream>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Node{
public:
  int data;
  Node* left = nullptr;
  Node* right = nullptr;
  Node(int data){
    this->data = data;
  }
};

class Pair{
public:
  Node* node = nullptr;
  int state = 0;
  Pair(Node* node, int state){
    this->node = node;
    this->state = state;
  }
};

Node* construct(vector<int>& arr){
  Node* root = new Node(arr[0]);
  pair<Node*, int> p = {root, 1};
  stack<pair<Node*, int>> st;
  st.push(p);
  int idx = 1;
  while (!st.empty()){
    if (st.top().second == 1){
      st.top().second++;
      if (arr[idx] != -1){
        st.top().first->left = new Node(arr[idx]);
        pair<Node*, int> lp = {st.top().first->left, 1};
        st.push(lp);
      }
      else{
        st.top().first->left = nullptr;
      }
      idx++;
    }
    else if(st.top().second == 2){
      st.top().second++;
      if(arr[idx] != -1){
        st.top().first->right = new Node(arr[idx]);
        pair<Node*, int> rp = {st.top().first->right, 1};
        st.push(rp);
      } 
      else{
        st.top().first->right = nullptr;
      }
      idx++;
    }
    else{
      st.pop();
    }
  }
  return root;
}

void iterativePrePostInTraversal(Node* node){
  Pair rtp = Pair(node, 1);
  stack<Pair> st;
  st.push(rtp);
  string pre;
  string post;
  string in;
  while (st.size() > 0){
    Pair upper = st.top();
    if (upper.state == 1){
      pre += to_string(upper.node->data) + " ";
      upper.state++;
      st.pop();
      st.push(upper);
      if (upper.node->left != nullptr) {
        Pair lp = Pair(upper.node->left, 1);
        st.push(lp);
      }
    }
    else if(upper.state == 2){
      in += to_string(upper.node->data) + " ";
      upper.state++;
      st.pop();
      st.push(upper);
      if (upper.node->right != nullptr){
        Pair rp = Pair(upper.node->right, 1);
        st.push(rp);
      }
    }
    else{
      post += to_string(upper.node->data) + " ";
      st.pop();
    }
  }
  cout<<pre<<endl;
  cout<<in<<endl;;
  cout<<post<<endl;;
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string temp;
    cin>>temp;
    if(temp == "n"){
      arr[i] = -1;
    } 
    else{
      arr[i] = stoi(temp);
    }
  }
  Node* root = construct(arr);
  iterativePrePostInTraversal(root);
}

/*Time Complexity: O(n)

The time complexity is linear due to the traversals in the Binary Tree.

Space Complexity: O(n)

The space complexity is linear due to the use of stack space.*/