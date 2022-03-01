/*1. You are required to complete the code of our QueueToStackAdapter class. 
2. As data members you've two queues available - mainQ and helperQ. mainQ is to contain data and helperQ is to assist in operations. (This is cryptic - take hint from video)
3. Here is the list of functions that you are supposed to complete
     3.1. push -> Should accept new data in LIFO manner.
     3.2. pop -> Should remove and return data in LIFO manner. If not available, print 
     "Stack underflow" and return -1.
    3.3. top -> Should return data in LIFO manner. If not available, print "Stack 
    underflow" and return -1.
    3.4. size -> Should return the number of elements available in the stack.
4. Input and Output is managed for you.

Note -> pop, top and size should work in constant time. push should work in linear time.

Constraints
Note -> pop, top and size should work in constant time. push should work in linear time.

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
size
pop
top
size
pop
top
size
pop
top
size
pop
top
size
pop
top
size
pop
top
size
pop
quit

Sample Output
11
7
11
4
6
4
2
5
2
8
4
8
5
3
5
20
2
20
10
1
10*/

#include <iostream>
#include <exception>
#include <queue>
using namespace std;

class QueueToStackAdapter{
    public:
    queue<int> mainQ;
    queue<int> helperQ;
    
    int size(){
        return mainQ.size();
    }
    
    void push(int data){
        if(mainQ.size()==0){
            mainQ.push(data);
            return;
        }
        while(mainQ.size()>0){
            int f = mainQ.front();
            mainQ.pop();
            helperQ.push(f);
        }
        mainQ.push(data);
        while(helperQ.size()>0){
            int f = helperQ.front();
            helperQ.pop();
            mainQ.push(f);
        }
    }

    int top(){
        int rem = mainQ.front();
        return rem;
    }

    int pop(){
        int rem = mainQ.front();
        mainQ.pop();
        return rem;
    }
};

int main(){
    QueueToStackAdapter st;
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
        cin>>str;
    }
    return 0;
}

/*Time & Space Complexity Analysis:-

Push - O(n): We are first removing all elements from main queue and adding them to helper queue, which is n * O(1) = O(n), 
then add the current element to be pushed to main queue, which is O(1), then add elements back from the helper queue by removing them one by one, which is n * O(1) = O(n) again.
Hence, the total time complexity will be O(n) per call, where n is the number of elements already present in the queue.

Size - O(1): We are just returning mainQ.size().

Pop - O(1): Checking if the queue has 0 size or not, and then popping the front element(using mainQ.remove()) are O(1) constant operations.

Top - O(1): Checking if the queue has 0 size or not, and then returning the front element (using mainQ.peek()) are O(1) constant operations.*/