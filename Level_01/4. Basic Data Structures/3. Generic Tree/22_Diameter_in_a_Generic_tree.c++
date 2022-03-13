/*1. You are given a partially written GenericTree class.
2. You are required to find and print the diameter of tree. THe diameter is defined as maximum number of edges between any two nodes in the tree. Check the question video for clarity.
3. Input is managed for you.

Constraints
None

Format
Input
Input is managed for you

Output
diameter

Example
Sample Input
20
10 20 -50 -1 60 -1 -1 30 -70 -1 80 -1 90 -1 -1 40 -100 -1 -1 -1

Sample Output
4*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    vector<Node*>children;
};

int dia = 0;
int diameter(Node* root){
    int ht = -1;
    int sh = -1;
    for (auto child: root->children){
      int ch = diameter(child);
      if (ch >= ht){
        sh = ht;
        ht = ch;
      } 
      else if (ch >= sh){
        sh = ch;
      }
    }
    if (sh + ht + 2 > dia){
      dia = sh + ht + 2;
    }
    ht += 1;
    return ht;
}

Node* construct(vector<int>&arr){
    Node* root = nullptr;
    stack <Node*> st;
    for (int i = 0; i < arr.size(); i++){
      if (arr[i] == -1){
        st.pop();
      } 
      else {
        Node* t = new Node();
        t->data = arr[i];
        if (st.size() > 0){
          st.top()->children.push_back(t);
        } 
        else{
          root = t;
        }
        st.push(t);
      }
    }
    return root;
}
  
int main(){
    int n,x;
    cin>>n;
    vector<int>arr;
    for(int i = 0;i < n;i++){
        cin>>x;
        arr.push_back(x);
    }
    Node *root = construct(arr);
    dia=0;
    diameter(root);
    cout<<dia<<endl;
}  

/*Time Complexity: O(n)

The time complexity for the function is linear as tree traversal is involved which is linear in terms of time complexity.

Space Complexity: O(h)

The space complexity for the function is proportional to the height of the generic tree due to the recursion stack.*/