class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0)
            return true;
        
        stack<char> st;

        for(auto it:s) {
            switch(it) {
                case '[':
                case '{':
                case '(':
                    st.push(it);
                    break;
                
                case ']':
                    if(st.empty())
                        return false;
                    if(st.top() != '[')
                        return false;
                    st.pop();
                    break;

                case '}':
                    if(st.empty())
                        return false;
                    if(st.top() != '{')
                        return false;
                    st.pop();
                    break;

                case ')':
                    if(st.empty())
                        return false;
                    if(st.top() != '(')
                        return false;
                    st.pop();
                    break;
            }
        }

        if(!st.empty())
            return false;

        return true;
    }
};
