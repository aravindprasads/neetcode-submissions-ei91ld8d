class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, mini = INT_MAX;
        for(auto it:prices) {
            if(mini == INT_MAX) {
                mini = it;
                continue;
            }
            if(mini > it) {
                mini = it;
                continue;
            }
            ans = max(ans, it - mini);
        }
        return ans;
    }
};
