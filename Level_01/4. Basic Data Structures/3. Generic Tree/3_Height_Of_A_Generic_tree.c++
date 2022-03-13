/*1. You are given a partially written GenericTree class.
2. You are required to complete the body of height function. The function is expected to find the height of tree. 
Depth of a node is defined as the number of edges it is away from the root (depth of root is 0). Height of a tree is defined as depth of deepest node.
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
12
10 20 -1 30 50 -1 60 -1 -1 40 -1 -1

Sample Output
2*/

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
            Node *t=newNode(arr[i]);
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

int height(Node *node){
    int h = -1;
    for(Node *child : node->children)
    {
        int ch = height(child);
        h = max(h,ch);
    }
    h = h+1;
    return h;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    Node *root = construct(arr,n);
    int h = height(root);
    cout<<h<<endl;
}     

/*Time Complexity: O(n)

We travel to all the elements of the tree. Every node is processed individually inside the 'for' loop.

Space Complexity: O(1)

No extra space is used. But when the function runs at that time, space acquired by the memory stack will be O(n).*/