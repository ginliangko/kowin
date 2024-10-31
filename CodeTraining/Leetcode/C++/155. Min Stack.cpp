/* 155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
*/

class MinStack {
private:
    vector<vector<int>> obj;

public:

    MinStack() {
    }
    
    void push(int val) {
        int min=getMin();
        if(obj.size()==0 || val<min) min=val;

        obj.push_back({val, min});
    }
    
    void pop() {
        obj.pop_back();
    }
    
    int top() {
        return obj.back()[0];
    }
    
    int getMin() {
        if(obj.size()<=0) return -1;
        return obj.back()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
