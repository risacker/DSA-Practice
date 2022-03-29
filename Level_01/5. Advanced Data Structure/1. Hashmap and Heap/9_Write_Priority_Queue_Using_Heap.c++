/*1. You are required to complete the code of our Priority Queue class using the heap data structure. 
2. Here is the list of functions that you are supposed to complete:
    2.1. add -> Should accept new data.
    2.2. remove -> Should remove and return smallest value, if available or print 
     "Underflow" otherwise and return -1.
     2.3. peek -> Should return smallest value, if available or print "Underflow" 
     otherwise and return -1.
     2.4. size -> Should return the number of elements available.
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
add 10
add 20
add 30
add 40
peek
add 50
peek
remove
peek
remove
peek
remove
peek
remove
peek
quit

Sample Output
10
10
10
20
20
30
30
40
40
50*/

#include<bits/stdc++.h>
using namespace std;

    vector<int> data;
    int _size(){
      return data.size();
    }
    
    void upheapify(int i) {
      while(i > 0){
          int pi = (i-1)/2;
          if(data.at(i) < data.at(pi)){
              swap(data[i],data[pi]);
          }
          else
             break;  
          i = pi;
      }
    }

    void downheapify(int i) {
      while(true){
          int li = i*2+1;
          int ri = i*2+2;  
          int mini = i; 
          if(li < data.size() && data.at(li) < data.at(mini)){
              mini = li;
          }
          if(ri < data.size() && data.at(ri) < data.at(mini)){
              mini = ri;
          }
          if(i == mini)
             break;
          swap(data[i],data[mini]);
          i = mini;    
      }
    }
    
    void add(int val) {
        data.push_back(val);
        upheapify(data.size() - 1);
    }

    int _remove() {
      if (_size() == 0) {
        cout<<"Underflow"<<endl;
        return -1;
      }
      swap(data[0], data[data.size() - 1]);
      int val = data[data.size()-1];
      data.pop_back();
      downheapify(0);
      return val;
    }  

    int peek(){
      if (_size() == 0) {
        cout<<"Underflow"<<endl;
        return -1;
      }
      return data.at(0);
    } 

int main(){ 
  while(1){
      string str;
        getline(cin,str);
      if(str[0] == 'a'){
          string num = str.substr(4,str.length());
          int val = stoi(num);
          add(val);
      }
      else if(str[0] == 'r'){
          int val = _remove();
          if(val != -1){
              cout<<val<<endl;
          }
      }
      else if(str[0] == 'p'){
          int val = peek();
          if(val != -1){
              cout<<val<<endl;
          }
      }
      else 
         break;
  }  
}