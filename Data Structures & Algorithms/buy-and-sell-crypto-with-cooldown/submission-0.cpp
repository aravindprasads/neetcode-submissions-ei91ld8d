/*
with and without
either buy or sell anyday and another - no op
*/

class Solution {
public:
    
    int helper(vector<int> arr, int index, bool is_buy, unordered_map<string, int>& dp) {
        if(index >= arr.size())
            return 0;
        
        int p1, p2;
        string key = to_string(index) + "," + to_string(is_buy);
        if(dp.find(key) != dp.end())
            return dp[key];

        //buy
        if(is_buy)
            p1 = -arr[index] + helper(arr, index+1, false, dp);
        else //sell
            p1 = arr[index] + helper(arr, index+2, true, dp);

        p2 = helper(arr, index+1, is_buy, dp);

        dp[key] = max(p1, p2);
        return dp[key];
    }
    
    int maxProfit(vector<int>& prices) {        
        unordered_map<string, int> dp;
        return helper(prices, 0, true, dp);
    }
};
