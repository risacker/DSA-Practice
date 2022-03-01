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
Note -> add and size should work in constant time. remove and peek should work in linear time.

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

#include <iostream>
#include <exception>
#include <stack>
using namespace std;

class StackToQueueAdapter{
    public:
    stack<int> mainS;
    stack<int> helperS;
    
    int size(){
        return mainS.size();
    }
    
    void add(int data){
        mainS.push(data);
    }

    int peek(){
        if (mainS.size() == 0){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        while(mainS.size()>1){
            int t = mainS.top();
            mainS.pop();
            helperS.push(t);
        }
        int rem = mainS.top();
        mainS.pop();
        helperS.push(rem);
        while(helperS.size()>0){
            int t = helperS.top();
            helperS.pop();
            mainS.push(t);
        }
        return rem;
    }

    int remove(){
        if (mainS.size() == 0){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        while(mainS.size()>1){
            int t = mainS.top();
            mainS.pop();
            helperS.push(t);
        }
        int rem = mainS.top();
        mainS.pop();
        while(helperS.size()>0){
            int t = helperS.top();
            helperS.pop();
            mainS.push(t);
        }
        return rem;
    }
};

int main(){
    StackToQueueAdapter q;
    string str;
    cin>>str;
    while(str!="quit"){
        if(str=="add"){
            int val;
            cin>>val;
            q.add(val);
        }
        else if(str=="remove"){
            int val = q.remove();
            if(val != -1){
                cout<<val<<endl;
            }
        }
        else if(str=="peek"){
            int val = q.peek();
            if(val != -1){
                cout<<val<<endl;
            }
        }
        else if(str=="size"){
            cout<<q.size()<<endl;
        }
        cin>>str;
    }
    return 0;
}

/*Time Complexity:-

Add: The time complexity is O(1) because we have used the stack push method.

Size: The time complexity is O(1) as we have just returned the size of the stack.

Peek: The time complexity of the peek method is O(n) as we pooped the entire stack of n elements and then pushed them back again. 
So, there are two traversals. So, the time complexity will be n+n=2n i.e. O(n).

Remove: The time complexity of this method is O(n) as we pooped the entire stack of n elements and then pushed them back again. 
So, there are two traversals. So, the time complexity will be n+n=2n i.e. O(n).

Space Complexity: O(1)

Well the space complexity can be considered as O(n) as we are using two stacks for implementing the queue. 
But, these two stacks are given to us in our question, and apart from these stacks, we have not used any extra data structure or memory to implement the queue. 
Since the data structure that is given in the question (2 stacks in this case) is not considered in the space complexity, the space complexity will be O(1).*/