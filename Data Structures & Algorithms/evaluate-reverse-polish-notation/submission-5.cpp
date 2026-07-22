class Solution {
public:

    int makeOp(int op1, int op2, string op) {       
        int ans = INT_MAX;

        if(op == "+")
            ans = op1+op2;
        else if(op == "-")
            ans = op1-op2;
        else if(op == "*")
            ans = op1*op2;
        else if(op == "/")
            ans = op1 / op2;

        return ans;
    }

    bool isOperator(string c) {        
        if((c == "+") || (c == "-") || (c == "*") || (c == "/"))
            return true;
        return false;
    }

    int evalRPN(vector<string>& tokens) {
        int i = 0;
        stack<int> st;

        while(i < tokens.size()) {
            if(!isOperator(tokens[i]))
                st.push(stoi(tokens[i]));
            else {
                int op2 = st.top(); 
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(makeOp(op1, op2, tokens[i]));
            }
            i++;
        }
        return st.top();
    }
};
