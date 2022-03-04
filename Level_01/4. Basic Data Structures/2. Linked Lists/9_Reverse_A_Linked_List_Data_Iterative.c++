/*1. You are given a partially written LinkedList class.
2. Here is a list of existing functions:
    2.1 addLast - adds a new element with given value to the end of Linked List
    2.2. display - Prints the elements of linked list from front to end in a single line. 
    All elements are separated by space
    2.3. size - Returns the number of elements in the linked list.
    2.4. removeFirst - Removes the first element from Linked List. 
    2.5. getFirst - Returns the data of first element. 
    2.6. getLast - Returns the data of last element. 
    2.7. getAt - Returns the data of element available at the index passed. 
    2.8. addFirst - adds a new element with given value in front of linked list.
    2.9. addAt - adds a new element at a given index.
    2.10. removeLast - removes the last element of linked list.
    2.11. removeAt - remove an element at a given index.
3. You are required to complete the body of reverseDI function. The function should be an iterative function and should reverse the contents of linked list by changing the "data" property of nodes.
4. Input and Output is managed for you.

Constraints
None

Format
Input
Input is managed for you

Output
Output is managed for you

Example
Sample Input
addFirst 10
addFirst 20
addLast 30
addLast 40
addLast 50
addFirst 60
removeAt 2
display
reverseDI
display
quit

Sample Output
60 20 30 40 50 
50 40 30 20 60*/

#include <iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;
};

class LinkedList {
    public: node* head=nullptr;
    node* tail=nullptr;
    int size_=0;

void insert_at_tail(int val){
    if(head==NULL){
        node *newnode = new node;
        newnode->val=val;
        newnode->next=NULL;
        head=newnode;
    }
    else{
        node *newnode = new node;
        newnode->val=val;
        newnode->next=NULL;
        node *temp = head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = newnode;
    }
}

void insertion_at_head(int val){
    node *newnode = new node;
    newnode->val=val;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode ->next =head;
        head = newnode;
    }
}

void print (){
    node *temp =head;
    if(head==NULL){
        cout << "0" << endl;
        return;
    }
     while(temp!=NULL){
         cout<<temp->val<<" ";
         temp=temp->next;
     }
     cout << endl;
}

void deletion_at_head(){
      if(head==NULL) 
        return;
      node *temp=head;
      head=head->next;
      delete temp;
}

void deletion_at_tail(){
    if(head==NULL) 
       return;
      node* previous=NULL;
      node* temp=head;
      while(temp->next!=NULL){
          previous=temp;
          temp=temp->next;
      }
      previous->next = NULL;
      delete temp; 
}

void last(){
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    cout << temp->val << endl;
}

int size(){
    int cnt=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

void first(){
    cout << head->val << endl;
}

node* getAt(int p){
    int cnt=0;
    node* temp=head;
    while(cnt < p){
        cnt++;
        temp=temp->next;
    }
    return temp;
}

void addAt(int pos,int data){
    if(pos==0){
        insertion_at_head(data);
        return;
    }
    node* newnode=new node;
    newnode->val=data;
    int cnt=0;
    node* temp=head;
    while(cnt<pos-1){
        cnt++;
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
}

void removeAt(int pos){ 
    if(pos==0){
        deletion_at_head();
        return;
    }
    int cnt=0;
    node* temp=head;
    while(cnt<pos-1){
        cnt++;
        temp=temp->next;
    }
    temp->next = temp->next->next;
}

void reverse_di(){
    int left = 0;
    int right = size() - 1;
    while(left < right){
        node* templ = getAt( left);
        node* tempr = getAt( right);
        
        int temp = templ->val;
        templ->val = tempr->val;
        tempr->val = temp;
        left++;
        right--;
    }
 }
};
int main() {
  LinkedList l1;
    string s;
    cin >> s;
    while(s!="quit"){
        if(s=="addLast"){
            int data;
            cin>> data;
            l1.insert_at_tail(data);
        }
        else if(s=="addFirst"){
            int data;
            cin>> data;
            l1.insertion_at_head(data);
        }
        else if(s=="getFirst"){
            if(l1.head!=NULL){
                l1.first();
            }else{
                cout << "List is empty" << endl;
            }
        }
        else if(s=="getLast"){
            if(l1.head!=NULL){
                l1.last();
            } 
            else
            {
                cout<<"List is empty";
            } 
        }
        else if(s=="removeFirst"){
            if(l1.head!=NULL){
                l1.deletion_at_head();
            }
            else{
                cout << "List is empty" << endl; 
            }
        }
        else if(s=="getAt"){
            if(l1.head!=NULL){
                int i;
                cin >> i; 
                if(i>=l1.size()){
                    cout << "Invalid arguments" << endl;
                }
                else{
                    l1.getAt(i);
                }
            }
            else
            {
                cout<<"List is empty";
            }    
        }
        else if(s=="display"){
            if(l1.head!=NULL){
                l1.print();
            }
            else{
                cout << endl;
            }
        }
        else if(s=="size"){
            if(l1.head!=NULL){
                 cout << l1.size() << endl;
            }
        }
        else if(s=="addAt"){
            int val,i;
            cin >> i >> val;
            if(i>l1.size()){
                cout << "Invalid arguments" << endl;
            }
            else{
                l1.addAt(i,val);
            }
        }
        else if(s == "removeLast"){
            if(l1.head!=NULL){
                l1.deletion_at_tail();
            }
            else{
                cout << "List is empty" << endl; 
            }
        }
        else if(s == "removeAt"){
            if(l1.head!=NULL){
                int i;
                cin >> i; 
                if(i>l1.size()){
                    cout << "Invalid arguments" << endl;
                }
                else{
                    l1.removeAt(i);
                }
            }
            else{
                cout << "List is empty" << endl; 
            }
        }
        else if(s == "reverseDI"){
            if(l1.head!=NULL){
                l1.reverse_di();
            }
            else{
                cout << "List is empty" <<endl; 
            }
        }
        cin >> s;
    }   
}

/*Time Complexity: O(n^2)

The getNodeAt() function is a linear function and the number of calls to that function will be at max n. 
Because we will do n/2 calls for the left node and n/2 for the right node. So the total complexity is n*O(n) = O(n^2)

Space Complexity: O(1)

We are not using any extra space so the space complexity will remain constant.*/