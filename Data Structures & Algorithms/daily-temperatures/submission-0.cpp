/*
Monotonic stack

stack -> number and index

read each number
if(stack empty)
    push to stack
if(number <= stacktop)
    push
if number > stack-top
    loop until number<=top:
        pop each element
        add curr-index - top-index and add to answer-index

pop elements from stack and add 0 to ans-index
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int> ans(arr.size(), 0);
        stack<pair<int, int>> st;

        for(int i=0; i<arr.size(); i++) {
            if((st.empty()) || (arr[i] <= st.top().first)) {
                st.push({arr[i], i});
                continue;
            }
            while(!st.empty() && arr[i] > st.top().first) {
                auto [val, ind] = st.top();
                ans[ind] = i-ind;
                st.pop();
            }
            st.push({arr[i], i});
        }
        return ans;
    }
};