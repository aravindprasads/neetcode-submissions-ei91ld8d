class Solution {
public:

    int helper(vector<int> arr, int index, int target, unordered_map<string, int>& dp) {
        if(target == 0)
            return 0;
        if(target < 0)
            return INT_MAX;
        if(index >= arr.size())
            return INT_MAX;
        
        string key = to_string(index) + "," + to_string(target);
        if(dp.find(key) != dp.end())
            return dp[key];

        int mini = INT_MAX;
        for(int i=0; (arr[index] * i) <= target; i++) {
            int res = helper(arr, index+1, target - (i * arr[index]), dp);
            if(res != INT_MAX) {
                res += i;
                mini = min(mini, res);
            }
        }

        dp[key] = mini;
        return mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        unordered_map<string, int> dp;
        int ans = helper(coins, 0, amount, dp);
        
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};
