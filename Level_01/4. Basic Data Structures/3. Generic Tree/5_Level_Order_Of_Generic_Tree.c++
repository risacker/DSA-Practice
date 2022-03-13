/*1. You are given a partially written GenericTree class.
2. You are required to complete the body of levelorder function. 
The function is expected to visit every node in "levelorder fashion". Please check the question video for more details.
3. Input is managed for you.

Constraints
None

Format
Input
Input is managed for you

Output
All nodes from left to right (level by level) all separated by a space and ending in a "."

Example
Sample Input
24
10 20 50 -1 60 -1 -1 30 70 -1 80 110 -1 120 -1 -1 90 -1 -1 40 100 -1 -1 -1

Sample Output
10 20 30 40 50 60 70 80 90 100 110 120 .
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    vector<Node*>children;
};

Node *newNode(int key){
	Node *temp = new Node;
	temp->data = key;
	return temp;
}

Node *construct(int arr[],int n ){
    Node *root = NULL;
    stack<Node*>st;
    for(int i = 0;i < n;i++){
        if(arr[i] == -1){
            st.pop();
        }
        else{
            Node *t = newNode(arr[i]);
            if(st.size() > 0){
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

void levelorder(Node *node)
{
  if(node==NULL)
    return;
  queue<Node*> q;
  q.push(node);
  while(q.size() > 0)
  {
      Node *temp = q.front();
      q.pop();
      cout<<temp->data<<" " ;
      for(Node *child : temp->children)
      {
          q.push(child);
      }
  }
  cout<<"."<<endl;
}

int main(){ 
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    Node *root = construct(arr,n);
    levelorder(root); 
}

/*Time Complexity: O(n)

We travel to all the elements of the tree. Every node is processed individually in a while loop.

Space Complexity: O(n)

A queue of size n will be used.*/