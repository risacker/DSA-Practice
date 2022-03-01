/*1. You are required to complete the code of our TwoStack class. The class should implement LIFO behaviours for two stacks in the same array.
2. Here is the list of functions that you are supposed to complete
    2.1. push1, push2 -> Should accept new data for appropriate stack if there is 
    space available in the underlying array or print "Stack overflow" otherwise.
    2.2. pop1, po2 -> Should remove and return data from appropriate stack if 
    available or print "Stack underflow" otherwise and return -1.
    2.3. top1, top2 -> Should return data from appropriate stack if available or print 
    "Stack underflow" otherwise and return -1.
    2.4. size1, size2 -> Should return the number of elements available in appropriate 
     stack.
3. Input and Output is managed for you.

Constraints
1. All fns should be constant in time.
2. Memory should be optimally used i.e. one of the stacks can use more elements in array but overflow should not happen before whole array is used.

Format
Input
Input is managed for you

Output
Output is managed for you

Example
Sample Input
5
push1 10
push1 20
push2 30
push2 40
push2 50
push1 60
top1
pop1
top1
pop1
top2
pop2
top2
pop2
top1
pop1
top2
pop2
quit

Sample Output
Stack overflow
20
20
10
10
50
50
40
40
Stack underflow
Stack underflow
30
30*/

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

   class TwoStack {
    public:
    vector<int> data;
    int tos1;
    int tos2;

     TwoStack(int cap) {
      tos1 = -1;
      tos2 = cap;
      data.resize(cap);
    }

    int size1() {
      return (tos1 + 1);
    }

    int size2() {
      return (data.size() - tos2);

    }

    void push1(int val) {
      if (tos1 + 1 == tos2){ 
      cout<<"Stack overflow"<<endl;
        return;
      }
      data[++tos1] = val;
    }

    void push2(int val) {
      if (tos1 + 1 == tos2) {
     cout<<"Stack overflow"<<endl;
        return;
      }
      data[--tos2] = val;
    }

    int pop1() {
      if (tos1 == -1) {
        cout<<"Stack underflow"<<endl;
        return -1;
      }
      return data[tos1--];
    }

    int pop2() {
      if (tos2 == data.size()) {
        cout<<"Stack underflow"<<endl;
        return -1;
      }
      return data[tos2++];
    }

    int top1() {
      if (tos1 == -1) {
        cout<<"Stack underflow"<<endl;
        return -1;
      }
      return data[tos1];
    }

    int top2() {
      if (tos2 == data.size()) {
        cout<<"Stack underflow"<<endl;
        return -1;
      }
      return data[tos2];
    }
  };

int main(){
    string str;
    int cap;
    cin>>cap;
    TwoStack st(cap);
    while (true) {
     getline(cin, str);
     if (str[0] == 'q') {
      break;
    }
     else if (str[0] == 'p'&& str[4]=='1') {
      string ss = str.substr(6, 2);
      int n = stoi(ss);
      st.push1(n);
    }
     else if (str[0] == 't'&&str[3]=='1') {
      int tp=st.top1();
      if(tp!=-1) 
       cout<<tp<<endl;
    }
     else if (str[0] == 'p'&&str[3]=='1') {
      int tp=st.pop1();
      if(tp!=-1) 
       cout<<tp<<endl;
    }
     else if (str[0] == 'p'&& str[4]=='2') {
       string ss = str.substr(6, 2);
       int n = stoi(ss);
       st.push2(n);
    }
     else if (str[0] == 't'&&str[3]=='2') {
      int tp=st.top2();
      if(tp!=-1)
       cout<<tp<<endl;
    }
     else if (str[0] == 'p'&&str[3]=='2') {
      int tp=st.pop2();
      if(tp!=-1) 
        cout<<tp<<endl;
    }  
  }
  return 0;
}

/*Time Complexity: O(1)

According to the question, all the functions are coded in constant time.

Space Complexity: O(n)

Since space is used optimally and stacks require n space, therefore, the complexity is linear.*/