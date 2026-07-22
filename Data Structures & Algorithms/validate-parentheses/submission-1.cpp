class Solution {
public:
    bool isValid(string s) {
        if(s == "")
            return true;
        int i=0;
        stack<char> st;

        while(i < s.length()) {
            if((s[i] == '(') || (s[i] == '{') || (s[i] == '[')) {
                st.push(s[i]);
            }
            else {
                if(st.empty())
                    return false;
                char ch = st.top();
                st.pop();
                if(s[i] == ')') {
                    if(ch != '(')
                        return false;
                } else if (s[i] == ']') {
                    if(ch != '[')
                        return false;
                } else {
                    if(ch != '{')
                        return false;
                }                            
            }
            i++;
        }

        if(st.empty())
            return true;

        return false;                
    }
};
