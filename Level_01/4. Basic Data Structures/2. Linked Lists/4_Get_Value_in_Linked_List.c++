/*1. You are given a partially written LinkedList class.
2. Here is a list of existing functions:
    2.1 addLast - adds a new element with given value to the end of Linked List
    2.2. display - Prints the elements of linked list from front to end in a single line. 
     All elements are separated by space.
2.3. size - Returns the number of elements in the linked list.
2.4. removeFirst - Removes the first element from Linked List. 
3. You are required to complete the body of getFirst, getLast and getAt function 
3.1. getFirst - Should return the data of first element. If empty should return -1 and print "List is empty".
3.2. getLast - Should return the data of last element. If empty should return -1 and print "List is empty".
3.3. getAt - Should return the data of element available at the index passed. If empty should return -1 and print "List is empty". If invalid index is passed, should return -1 and print "Invalid arguments".
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
addLast 10
getFirst
addLast 20
addLast 30
getFirst
getLast
getAt 1
addLast 40
getLast
addLast 50
removeFirst
getFirst
removeFirst
removeFirst
getAt 3
removeFirst
removeFirst
getFirst
quit

Sample Output
10
10
30
20
40
20
Invalid arguments
List is empty*/

#include <iostream>
using namespace std;

class node{
   public:
    int val;
    node* next;
};

class LinkedList {
   public: 
    node* head=nullptr;
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

void print(){
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

int size(){
    int cnt=0;
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}

void getFirst(){
    cout<<head->val<<endl;
}

void getLast(){
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    cout << temp->val << endl;
}

node* getAt(int p){
    int cnt=0;
    node* temp=head;
    while(cnt < p){
        cnt++;
        temp=temp->next;
    }
    cout << temp->val << endl;
    return temp;
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
        else if(s=="getFirst"){
            if(l1.head!=NULL){
                l1.getFirst();
            }
            else{
                cout << "List is empty" << endl;
            }
        }
        else if(s=="getLast"){
            if(l1.head!=NULL){
                l1.getLast();
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
        cin>>s;
    }
}                        