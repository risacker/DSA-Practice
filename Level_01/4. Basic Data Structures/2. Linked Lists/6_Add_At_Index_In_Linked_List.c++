/*1. You are given a partially written LinkedList class.
2. Here is a list of existing functions:
  2.1 addLast - adds a new element with given value to the end of Linked List
  2.2. display - Prints the elements of linked list from front to end in a single line. All 
  elements are separated by space
  2.3. size - Returns the number of elements in the linked list.
  2.4. removeFirst - Removes the first element from Linked List. 
  2.5. getFirst - Returns the data of first element. 
  2.6. getLast - Returns the data of last element. 
  2.7. getAt - Returns the data of element available at the index passed. 
  2.8. addFirst - adds a new element with given value in front of linked list.
3. You are required to complete the body of addAt function. This function should add the element at the index mentioned as parameter. If the idx is inappropriate print "Invalid arguments".
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
getFirst
addAt 0 20
getFirst
getLast
display
size
addAt 2 40
getLast
addAt 1 50
addFirst 30
removeFirst
getFirst
removeFirst
removeFirst
addAt 2 60
display
size
removeFirst
removeFirst
getFirst
quit

Sample Output
10
20
10
20 10 
2
40
20
10 40 60 
3
60*/

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

void addFirst(int val){
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

void addAt(int pos,int data){
    if(pos==0){
        addFirst(data);
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
};

int main(){
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
            cin>>data;
            l1.addFirst(data);
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
        else if(s=="addAt"){
            int val,i;
            cin>>i>>val;
            if(i>l1.size()){
                cout<<"Invalid arguments"<<endl;
            }
            else{
                l1.addAt(i,val);
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

/*Time Complexity: O(n)

We are running a single loop to idx-1, at the worst case it might be size-1, so the time complexity will be O(n) linear.

Space Complexity: O(1)

We are not using any auxiliary space other than a single new node, So the space complexity is constant as well.*/