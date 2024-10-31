/* 155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
*/


#define STACK_LEN   10240

typedef struct {
    int *data;
    int *min;
    int idx;
} MinStack;

MinStack* minStackCreate() {
    MinStack *obj=malloc(sizeof(MinStack));
    obj->data=malloc(STACK_LEN*sizeof(int));
    obj->min=malloc(STACK_LEN*sizeof(int));
    obj->idx = 0;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    if(obj->idx<STACK_LEN) {
        if(obj->idx<=0)
            obj->min[obj->idx]=val;
        else
            obj->min[obj->idx]=obj->min[obj->idx-1]<val?obj->min[obj->idx-1]:val;
        obj->data[obj->idx++]=val;
    }
}

void minStackPop(MinStack* obj) {
    if(obj->idx>0)
        obj->idx--;
}

int minStackTop(MinStack* obj) {
    if(obj->idx<0 || obj->idx>STACK_LEN)
        return -1;
    return obj->data[obj->idx-1];
}

int minStackGetMin(MinStack* obj) {
    if(obj->idx==0) return -1;
    return obj->min[obj->idx-1];
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/* original solution
class MinStack {
private:
    int sz = 1000;
    int sp;
    int *buff;
    int min;
public:
    // initialize your data structure here.
    MinStack() {
        buff = (int *)malloc(sz * sizeof(int));
        //assert(buff);
        sp = 0;
    }
    
    void push(int x) {
        if (sp == 0 || min > x) min = x;
        if (sp == sz) {
            sz = sz * 2;
            buff = (int *)realloc((void *)buff, sz * sizeof(int));
            //assert(buff);
        }
        buff[sp ++] = x;
    }
    
    void pop() {
        int i, x = buff[-- sp];
        if (min == x) {
            for (i = 0; i < sp; i ++) {
                if (i == 0 || min > buff[i]) min = buff[i];
            }
        }
    }
    
    int top() {
        if (sp) return buff[(sp - 1)];
        return -1;
    }
    
    int getMin() {
        return min;
    }
};
​*/

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


/*
Difficulty:Easy
Total Accepted:138.3K
Total Submissions:482.9K


Companies Google Uber Zenefits Amazon Snapchat Bloomberg
Related Topics Stack Design
Similar Questions 
                
                  
                    Sliding Window Maximum
*/
