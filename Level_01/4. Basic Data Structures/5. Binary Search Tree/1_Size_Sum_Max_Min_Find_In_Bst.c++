/*1. You are given a partially written BST class.
2. You are required to complete the body of size, sum, max, min and find function. The functions are expected to:
    2.1. size - return the number of nodes in BST
    2.2. sum - return the sum of nodes in BST
    2.3. max - return the value of node with greatest value in BST
    2.4. min - return the value of node with smallest value in BST
    2.5. find - return true if there is node in the tree equal to "data"
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
19
50 25 12 n n 37 30 n n n 75 62 n 70 n n 87 n n
70

Sample Output
9
448
87
12
true*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
  Node(int val){
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

Node* construct(vector<int>& arr){
  Node* root = new Node(arr[0]);
  pair<Node*, int> p = {root, 1};
  stack<pair<Node*, int>> st;
  st.push(p);
  int idx = 1;
  while(!st.empty()){
    if(st.top().second == 1){
      st.top().second++;
      if(arr[idx] != -1) {
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

int min(Node *node){
    if(node->left == nullptr){
        return node->data;
    }  
    return min(node->left);
}

int max(Node *node){
    if(node->right == nullptr){
        return node->data;
    }  
    return max(node->right);
}

int sum(Node * node){  
    if(node == nullptr){
        return 0;
    }  
    int ls = sum(node->left);
    int rs = sum(node->right);  
    return ls + rs + node->data;
}


int size(Node * node){  
    if(node == nullptr){
        return 0;
    }  
    int ls = size(node->left);
    int rs = size(node->right);  
    return ls + rs + 1;
}

bool find(Node * node, int data){  
    if(node == nullptr){
        return false;
    }  
    if(node->data == data){
        return true;
    }
    else if(node->data < data){
        return find(node->right, data);
    }
    else{
        return find(node->left, data);
    }
}

int main(){
  int n;
  cin>>n;
  vector<int> arr(n, 0);
  for(int i = 0; i < n; i++){
    string x;
    cin>>x;
    if(x == "n"){
      arr[i] = -1;
    }
    else{
      arr[i] = stoi(x);
    }
  }
  int data;
  cin>>data;
  Node* root = construct(arr);
  cout<<size(root)<<"\n"<<sum(root)<<"\n"<<max(root)<<"\n"<<min(root)<<"\n";
  if(find(root, data)){
    cout<<"true"<<endl;
  }
  else{
    cout<<"false"<<endl;
  }
}

/*Time Complexity: O(n)

Size(): The time complexity of this method is O(n) as we have traversed all the nodes to count them.

Sum(): The time complexity of this method is O(n) as we have traversed all the nodes to add their values into the size.

Max(): The time complexity of this function is O(log2n) as we are not traversing the complete tree. 
We are at-most traversing the height of the tree which is O(log2n). This is the average case scenario.. 
If the tree has all the nodes only on the left side (left-skewed) or only on the right side (right-skewed) then the height will become O(n) and the time complexity will also be O(n).

Min(): Same as above for max.

Find(): The time complexity of find is also O(log2n). This is also the average case complexity. It may reach O(n) in the worst case if the tree is left skewed or right skewed.

Space Complexity: O(h)

The space complexity for all these methods will be O(1) without considering the recursion space and O(h) where h is the max height of the recursion stack which is the same as the height of the tree if we consider the recursion space. 
This h is O(log2n) in an average case scenario but in the worst case scenario it can also be O(n).*/