/*1. You are given a partially written GenericTree class.
2. You are required to find the ceil and floor value of a given element. Use the "travel and change" strategy explained in the earlier video. 
The static properties - ceil and floor have been declared for you. You can declare more if you want. If the element is largest ceil will be largest integer value (32 bits), if element is smallest floor will be smallest integer value (32 bits). 
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
10 20 -50 -1 60 -1 -1 30 70 -1 -80 110 -1 -120 -1 -1 90 -1 -1 40 -100 -1 -1 -1
70

Sample Output
CEIL = 90
FLOOR = 60*/

#include<bits/stdc++.h>
#include<iostream>
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

int c = INT_MAX;
int flloor = INT_MIN;
void cnf(Node *node, int data){
    if(node->data > data)
    {
        if(node->data < c)
        {
            c = node->data;
        }
    }
    else if(node->data < data)
    {
        if(node->data > flloor)
        {
            flloor = node->data;
        }
    }    
    for(Node *child : node->children)
    {
        cnf(child,data);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    int data;
    cin>>data;
    Node *root = construct(arr,n);
    cnf(root,data);
    cout<<"CEIL = "<<c<<endl;
    cout<<"FLOOR = "<<flloor<<endl;
}

/*Time Complexity: O(n)

The time complexity of this solution is O(n) as we are traversing all the nodes of the tree.

Space Complexity: O(1)

The space complexity of this solution is O(1). Again like almost every previous question, if we consider the recursion space the time complexity becomes O(logn) as the maximum height of the stack can be equal to the height of the tree i.e. O(logn).*/