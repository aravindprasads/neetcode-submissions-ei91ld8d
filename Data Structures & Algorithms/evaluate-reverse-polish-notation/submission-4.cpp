class Solution {
public:

    void calc(stack<int>& st, string op) {
        if(st.size() < 2)
            return;
        int op2 = st.top();
        st.pop();
        int op1 = st.top();
        st.pop();        
        if(op == "+")
            st.push(op1 + op2);
        else if(op == "-")            
            st.push(op1 - op2);
        else if(op == "*")
            st.push(op1 * op2);            
        else if(op == "/")
            st.push(op1 / op2);                   
    }

    int conv(string s) {
        if(s == "")
            return 0;
        int ans = 0;
        bool neg = false;
        for(auto it:s) {
            if(it == '-') {
                neg = true;
                continue;
            }
            ans = ((ans*10) + (int(it) - int('0')));
        }
        if(neg)
            ans = ans * -1;
        cout<<s<<" "<<ans<<endl; 
        return ans;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st; 
        if(tokens.size() == 0)
            return INT_MAX;
        
        for(auto it:tokens) {
            if((it == "+") || 
                (it == "-") || 
                (it == "*") || 
                (it == "/")) {
                    calc(st, it);
            }
            else {
                int val = conv(it);
                st.push(val);
            }
        }

        if(st.empty())
            return INT_MAX;
        return st.top();
    }    
};
