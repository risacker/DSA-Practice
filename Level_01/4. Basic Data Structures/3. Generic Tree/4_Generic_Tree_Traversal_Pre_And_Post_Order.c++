/*1. You are given a partially written GenericTree class.
2. You are required to complete the body of traversals function. The function is expected to visit every node. While traversing the function must print following content in different situations.
   2.1. When the control reaches the node for the first time -> "Node Pre" node.data.
   2.2. Before the control leaves for a child node from a node -> "Edge Pre" 
   node.data--child.data.
   2.3. After the control comes back to a node from a child -> "Edge Post" node.data--child.data.
   2.4. When the control is about to leave node, after the children have been visited -> "Node Post" node.data.
3. Input is managed for you.

Constraints
None

Format
Input
Input is managed for you

Output
As suggested in Sample Output

Example
Sample Input
12
10 20 -1 30 50 -1 60 -1 -1 40 -1 -1

Sample Output
Node Pre 10
Edge Pre 10--20
Node Pre 20
Node Post 20
Edge Post 10--20
Edge Pre 10--30
Node Pre 30
Edge Pre 30--50
Node Pre 50
Node Post 50
Edge Post 30--50
Edge Pre 30--60
Node Pre 60
Node Post 60
Edge Post 30--60
Node Post 30
Edge Post 10--30
Edge Pre 10--40
Node Pre 40
Node Post 40
Edge Post 10--40
Node Post 10
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

void traversals(Node *node)
{
   cout<<"Node Pre "<<node->data<<endl;
   for(Node *child : node->children)
   {
       cout<<"Edge Pre "<<node->data<<"--"<<child->data<<endl;
       traversals(child);
       cout<<"Edge Post "<<node->data<<"--"<<child->data<<endl;
   }
   cout<<"Node Post "<<node->data<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    Node *root = construct(arr,n);
    traversals(root);
}

/*Time Complexity: O(2^n)

Space Complexity: O(1)

Since no extra space is used in the program, therefore the space complexity is constant. 
This complexity is not including the space required for the recursion stack.*/