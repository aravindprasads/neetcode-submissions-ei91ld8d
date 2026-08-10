class Solution {
public:

    int helper(vector<int> arr, int index, int target, unordered_map<string, int>& dp) {
        if(target == 0)
            return 1;
        if(index >= arr.size())
            return 0;
        
        string key = to_string(index) + "," + to_string(target);
        if(dp.find(key) != dp.end())
            return dp[key];

        int cnt=0;
        for(int i=0; target - (arr[index]*i) >= 0; i++) {
            cnt += helper(arr, index+1, target-(arr[index]*i), dp);
        }
        dp[key] = cnt;
        return dp[key];
    }


    int change(int amount, vector<int>& coins) {
        unordered_map<string, int> dp;
        return helper(coins, 0, amount, dp);
    }
};
