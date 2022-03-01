/*1. You are required to complete the code of our MinStack class. 
2. As data members you've two stacks available in the class - one for data values and another for minimum values. (This is cryptic - take hint from video)
2. Here is the list of functions that you are supposed to complete
2.1. push -> Should accept new data in LIFO manner
2.2. pop -> Should remove and return data in LIFO manner. If not available, print "Stack underflow" and return -1.
2.3. top -> Should return data in LIFO manner. If not available, print "Stack underflow" and return -1.
2.4. size -> Should return the number of elements available in the stack
2.5. min -> Should return the smallest element available in the stack. If not available, print "Stack underflow" and return -1.
3. Input and Output is managed for you.

Note -> The judge maynot be able to check if all your functions are O(1) in time, but that is what the expectation is.

Constraints
None

Format
Input
Input is managed for you

Output
Output is managed for you

Example
Sample Input
push 10
push 20
push 5
push 8
push 2
push 4
push 11
top
min
pop
top
min
pop
top
min
pop
top
min
pop
top
min
pop
top
min
pop
top
min
pop
quit

Sample Output
11
2
11
4
2
4
2
2
2
8
5
8
5
5
5
20
10
20
10
10
10*/

#include<iostream>
#include <string>
#include <stack>
using namespace std;

class MinStack{
    stack<int> data;
    int minVal;

 public:    
    int size() {
        return data.size();      
    }

 public:
    void push(int val) {
      if(size() == 0){
          minVal = val;
          data.push(val);
      }
      else if(val >= minVal){
          data.push(val);
      }
      else{
          data.push(val + val - minVal); // encodings
          minVal = val;
      }
    }

 public:
    int pop() {
      if(size() == 0){
          cout << "Stack underflow" << endl;
          return -1;
      }
      else{
          int val = data.top();
          data.pop();  
          if(val >= minVal){
              int v2r = val;
              return v2r;
          }
          else{
              int v2r = minVal;
              minVal = 2 * minVal - val;
              return v2r;
          }
      }
    }

 public:
    int top() {
      if(size() == 0){
          cout << "Stack underflow" << endl;
          return -1;
      }
      else{
          int val = data.top();
          if(val >= minVal){
              return val;
          }
          else{
              return minVal;
          }
      }
    }
   
 public:
    int min(){
    if(size() == 0){
       cout << "Stack underflow" << endl;
       return -1;
    }
    else{
       return minVal;
    }
  }   
};

int main(){
    MinStack st;  
    string str;
    cin>>str;  
    while(str != "quit"){    
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
      else if(str== "min" ){
          int val = st.min();
          if(val != -1){
            cout << val << endl;  
          }
      }     
      cin>>str;
    }
}

/*Time Complexity : O(1)

According to the question, we were required to write all the functions in linear time which we have.

SPACE COMPLEXITY : O(n)

The space complexity is of order n because stacks of n spaces are used.*/