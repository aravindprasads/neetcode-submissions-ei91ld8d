class MinStack {
public:

    stack<int> st, minst;

    MinStack() {
        return;    
    }
    
    void push(int val) {
        st.push(val);
        
        if(minst.empty())
            minst.push(val);
        else if(minst.top() >= val)
            minst.push(val);
    }
    
    void pop() {
        if(st.empty())
            return;

        if(minst.top() == st.top())
            minst.pop();

        st.pop();        
    }
    
    int top() {
        if(st.empty())
            return -1;
        return st.top();
    }
    
    int getMin() {
        if(minst.empty())
            return -1;
        return minst.top();
    }
};