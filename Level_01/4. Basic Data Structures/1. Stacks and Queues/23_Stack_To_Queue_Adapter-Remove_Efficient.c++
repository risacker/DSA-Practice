/*1. You are required to complete the code of our StackToQueueAdapter class. The class should mimic the behaviour of a Queue and implement FIFO semantic.
2. Here is the list of functions that are written in the class
    2.1. add -> Accepts new data if there is space available in the underlying array or 
    print "Queue overflow" otherwise.
    2.2. remove -> Removes and returns value according to FIFO, if available or print 
    "Queue underflow" otherwise and return -1.
    2.3. peek -> Returns value according to FIFO, if available or print "Queue 
    underflow" otherwise and return -1.
    2.4. size -> Returns the number of elements available in the queue.
3. Input and Output is managed for you.

Constraints
Note -> remove, peek and size should work in constant time. add should work in linear time.

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
add 50
remove
remove
add 60
add 70
peek
remove
peek
remove
peek
remove
peek
remove
peek
remove
peek
remove
quit

Sample Output
10
20
30
30
40
40
50
50
60
60
70
70
Queue underflow
Queue underflow*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class StackToQueueAdapter {
public:
  stack <int> mainS;
  stack <int> helperS;

  int size() {
    return mainS.size();
  }

  void add(int val) {

    while (mainS.size() > 0) {
      helperS.push(mainS.top());
      mainS.pop();
    }
    mainS.push(val);
    while (helperS.size() > 0) {
      mainS.push(helperS.top());
      helperS.pop();
    }
  }

  int Remove() {
    if (mainS.size() == 0) {
      cout << "Queue underflow" << endl;
      return -1;
    }
    int tr = mainS.top();
    mainS.pop();
    return tr;
  }

  int peek() {
    if (mainS.size() == 0) {
      cout << "Queue underflow" << endl;
      return -1;
    }
    return mainS.top();
  }
};

int main(){
    string str;
  StackToQueueAdapter qu;
  while (true) {
    getline(cin, str);
    if (str[0] == 'q') {
      break;
    }
    else if (str[0] == 'a') {
      string ss = str.substr(4, 2);
      int n = stoi(ss);
      qu.add(n);
    }
    else if (str[0] == 's') {
      cout << qu.size() << endl;
    }
    else if (str[0] == 'r') {
      int val = qu.Remove();
      if (val != -1) {
        cout << val << endl;
      }
    } else if (str[0] == 'p') {
      int val = qu.peek();
      if (val != -1) {
        cout << val << endl;
      }
    }
  }
  return 0;
}

/*Time Complexity:-

Add: The time complexity is O(n) as we are popping all the values from the main stack and pushing them into the helper stack and doing vice-versa. 
So, the time complexity becomes n+n=2n=O(n).

Remove: The time complexity for this method is O(1) as we just popped a value from the main stack.

Size: The time complexity is O(1) as we just return the size of the main stack.

Peek: The time complexity is O(1) as we just use the peek method of the main stack.

Space Complexity: O(1)

Well the space complexity can be considered as O(n) as we are using two stacks for implementing the queue. But, these two stacks are given to us in our question, and apart from these stacks, we have not used any extra data structure or memory to implement the queue. 
Since the data structure that is given in the question (2 stacks in this case) is not considered in the space complexity, the space complexity will be O(1).*/