/*1. You are required to complete the code of our CustomStack class. The class should mimic the behaviour of java.util.Stack class and implement LIFO semantic.
2. Here is the list of functions that you are supposed to complete
   2.1. push -> Should accept new data if there is space available in the underlying 
   array or print "Stack overflow" otherwise.
   2.2. pop -> Should remove and return last data if available or print "Stack 
   underflow" otherwise and return -1.
   2.3. top -> Should return last data if available or print "Stack underflow" 
   otherwise and return -1.
   2.4. size -> Should return the number of elements available in the stack.
   2.5. display -> Should print the elements of stack in LIFO manner (space- 
   separated) ending with a line-break.
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
5
push 10
display
push 20
display
push 30
display
push 40
display
push 50
display
push 60
display
top
pop
display
top
pop
display
top
pop
display
top
pop
display
top
pop
display
top
pop
quit

Sample Output
10 
20 10 
30 20 10 
40 30 20 10 
50 40 30 20 10 
Stack overflow
50 40 30 20 10 
50
50
40 30 20 10 
40
40
30 20 10 
30
30
20 10 
20
20
10 
10
10
Stack underflow
Stack underflow*/

#include <iostream>
#include <exception>
using namespace std;

class Stack{    
    public:
        int *arr;
        int tos;
        int MaxCapacity;  
   public:
        Stack(int size){
            this->MaxCapacity = size;
            this->arr = new int[this->MaxCapacity];
            this->tos = -1;
        }  
   public:
        Stack(){
            Stack(10);
        } 
   public:
        int size(){
            return tos+1;
        }      
   public:
        void push(int data){
            if (tos == MaxCapacity - 1){
                cout<<"Stack overflow"<<endl;
                return;
            }
            tos++;
            arr[tos] = data;
        } 
   public:
        int top()
        {
            if (tos == -1){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            return arr[tos];
        } 
   public:
        int pop()
        {
            if (tos == -1){
                cout<<"Stack underflow"<<endl;
                return -1;
            }
            int rv = arr[tos];
            tos--;
            return rv;
        }    
    public:   
        void display() {
        for(int i=tos ;i>=0 ;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int n;
    cin>>n;
    Stack st(n);
    string str;
    cin>>str;
    while(str!="quit"){
      if(str=="push"){
        int val;
        cin>>val;
        st.push(val);
      } 
      else if(str=="pop"){
        int val = st.pop();
        if(val != -1){
          cout<<val<<endl;
        }
      } 
      else if(str=="top"){
        int val = st.top();
        if(val != -1){
          cout<<val<<endl;
        } 
      } 
      else if(str=="size"){
        cout<<st.size()<<endl;
      } 
      else if(str=="display"){
        st.display();
      }
      cin>>str;
    }
}     

/*Time Complexity : O(n)

A "for" loop has been used to print the entire stack which takes O(n) time, n being the number of elements in the stack.

SPACE COMPLEXITY : O(1)

Since no extra space is used therefore space complexity remains constant.*/