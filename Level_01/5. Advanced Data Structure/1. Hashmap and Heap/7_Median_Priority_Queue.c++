/*1. You are required to complete the code of our MedianPriorityQueue class. The class should mimic the behaviour of a PriorityQueue and give highest priority to median of it's data.
2. Here is the list of functions that you are supposed to complete
2.1. add -> Should accept new data.
2.2. remove -> Should remove and return median value, if available or print "Underflow" otherwise and return -1
2.3. peek -> Should return median value, if available or print "Underflow" otherwise and return -1
2.4. size -> Should return the number of elements available
3. Input and Output is managed for you.

Note -> If there are even number of elements in the MedianPriorityQueue, consider the smaller median as median value.

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
20
30
30
20
20
40
40
10
10
50*/

#include <iostream>
#include <queue>
using namespace std;

class MedianPriorityQueue{
    public:
    priority_queue <int> left;
    priority_queue <int, vector<int>, greater<int>> right;
    
    void push(int val){
        if(size() == 0){
            left.push(val);
        }
        else if(left.size() > 0 && val <= left.top()){
            left.push(val);
        }
        else{
            right.push(val);
        }
        
        if(left.size() + 2 == right.size()){ // left is small
            left.push(right.top());
            right.pop();
        }
        else if(right.size() + 2 == left.size()){ // right is small
            right.push(left.top());
            left.pop();
        }
    }
    
    int pop(){
        if(size() == 0){
            cout<<"Underflow"<<endl;
            return -1;
        }
        
        if(left.size() >= right.size()){
            int top = left.top();
            left.pop();
            return top;
        }
        else{
            int top = right.top();
            right.pop();
            return top;
        }
    }
    
    int top(){
        if(size() == 0) {
            cout<<"Underflow"<<endl;
            return -1;
        }
        
        if(left.size() >= right.size()){
            return left.top();
        }
        else{
            return right.top();
        }
    }
    
    int size(){
        return left.size() + right.size();
    }
};

int main(){
    MedianPriorityQueue pq;
    string str;
    cin>>str;
    while(str != "quit"){
        if(str == "add"){
            int val;
            cin>>val;
            pq.push(val);
        }
        else if(str == "remove"){
            int val = pq.pop();
            if(val != -1) {
                cout<<val<<endl;
            }
        }
        else if(str == "peek"){
            int val = pq.top();
            if(val != -1) {
                cout<<val<<endl;
            }
        }
        else if(str == "size"){
            cout<<pq.size()<<endl;
        }
        cin>>str;
    }  
    return 0;
}

/*Time Complexity:-

Add: The time complexity of this method is O(logn) same as the time complexity for adding in a priority queue as we are using the priority queue directly and adding the values into it.
Remove: The time complexity for remove is O(logn) as we have removed the elements from the priority queue and it takes O(logn) time to remove an element from the priority queue.
Peek: The time taken for peek is O(1) as we are just using the peek() method of priority queue.
Size: The time complexity for size is also O(1) as we are just returning the sum of sizes of both the queues and it takes O(1) time to calculate the size of priority queues using size() function.

Space Complexity: O(1)

The space complexity for all the methods is O(1) as we have not used any extra space for any method. We have taken two priority queues but they will not be counted in space complexity as it is not extra space. 
The question was to create a median priority queue and we have just done that using the two priority queues.*/