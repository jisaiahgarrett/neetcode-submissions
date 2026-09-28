// We can implement this with a stack, and just track the minimum number.
// We could keep a reference to the minimum number, or a count of how far
// down it is.
// However, if we keep a count of how far down it is, then our access is 
// O(n).
// Oh interesting, two stacks.
// 

class MinStack {
private:
    stack<int> inner_stack;
    stack<int> min_prefix;
public:
    MinStack() : inner_stack(), min_prefix() {
        std::cout << "Completed constructor" << std::endl;
    }
    
    void push(int val) {
        // always, push the value onto the inner stack.
        inner_stack.push(val);
        // push the minimum of val and the top of the min_prefix stack onto
        // min_prefix
        if (!min_prefix.empty()) {
            // We have an element, push the minimum of the two.
            min_prefix.push(min(val, min_prefix.top()));
        } else {
            // min_prefix is empty, push val.
            min_prefix.push(val);
        }
    }
    
    void pop() {
        std::cout << "about to pop the stacks" << std::endl;
        if (!inner_stack.empty()) {
            min_prefix.pop();
            inner_stack.pop();
        }
    }
    
    int top() {
        return inner_stack.top();
    }
    
    int getMin() {
        return min_prefix.top();
    }
};
