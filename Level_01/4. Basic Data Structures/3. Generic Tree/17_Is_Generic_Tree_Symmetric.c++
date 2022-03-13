/*1. You are given a partially written GenericTree class.
2. You are required to complete the body of IsSymmetric function. The function is expected to check if the tree is symmetric, if so return true otherwise return false. For knowing symmetricity think of face and hand. 
Face is symmetric while palm is not. Also, we are check only smmetricity of shape and not content. Check the question video for clarity.
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
20
10 20 50 -1 60 -1 -1 30 70 -1 80 -1 90 -1 -1 40 100 -1 110 -1 -1 -1

Sample Output
true*/

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

bool aremirror(Node *n1, Node *n2)
{
    if(n1->children.size() != n2->children.size())
    {
        return false;
    } 
    for(int i = 0;i < n1->children.size();i++)
    {
            int j=n2->children.size()-1-i;
            Node *c1 = n1->children.at(i);
            Node *c2 = n2->children.at(j);
            if(aremirror(c1,c2) == false)
            {
                return false;
            }
    }
    return true;
}

bool issym(Node *node)
{
    return aremirror(node, node);
}

int main(){  
    int n;
    cin>>n;  
    int arr[n];
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    Node *root = construct(arr,n);
    bool sym = issym(root);
    if(sym == 1){
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
}

/*Time Complexity: O(n)

We travel to all the elements of the tree. Every node is processed individually.

Space Complexity: O(1)

No extra space is used therefore space complexity remains constant. But when the function runs at that time, space acquired by the memory stack will be O(n).*/