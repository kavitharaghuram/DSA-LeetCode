class MinStack {
public:
    std::stack<int> stack;
    std::stack<int> minstack;
    MinStack() {
        
    }
    
    void push(int val) {
        stack.push(val);
        val= min(val, minstack.empty()? val: minstack.top());
        minstack.push(val);
    }
    
    void pop() {
        stack.pop();
        minstack.pop();
    }
    
    int top() {
        return stack.top();
    }
    
    int getMin() {
        return minstack.top();
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