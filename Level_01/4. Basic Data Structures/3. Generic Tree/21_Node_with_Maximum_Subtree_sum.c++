/*1. You are given a partially written GenericTree class.
2. You are required to find and print the node which has the subtree with largest sum. Also print the sum of the concerned subtree separated from node's value by an '@'. Refer the question video for clarity.
3. Input is managed for you.

Constraints
None

Format
Input
Input is managed for you

Output
@

Example
Sample Input
20
10 20 -50 -1 60 -1 -1 30 -70 -1 80 -1 90 -1 -1 40 -100 -1 -1 -1

Sample Output
30@130
*/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int c = INT_MAX;
int flloor = INT_MIN;

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

int msum = 0;
int msumnode = 0;
int subsumtree(Node *node)
{
    int sum = 0;
    for(Node *child : node->children)
    {
        int csum = subsumtree(child);
        sum = sum+csum;
    }
    sum = sum + node->data;
    if(sum > msum)
    {
        msumnode = node->data;
        msum = sum;
    }
    return sum;
}

int main(){  
    int n;
    cin>>n;   
    int arr[n];
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    Node *root = construct(arr,n);
    subsumtree(root);
    cout<<msumnode<<"@"<<msum<<endl;
}

/*Time Complexity:-

We are visiting each node exactly once, hence the total time complexity will be O(n) where n = number of nodes in the tree.

Space Complexity:-

We are just taking two integer variables mSum and mSumNode to find the maximum subtree sum. Hence, we are taking O(1) auxiliary space.
However, again, due to recursion, the recursion call stack will take up O(d) space where d = maximum depth of the tree.*/