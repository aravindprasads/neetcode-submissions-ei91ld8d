class Solution {
public:

    bool helper(vector<int>arr, int index, int target, unordered_map<string, bool>& dp) {
        if(target == 0)
            return true;            

        if(index >= arr.size())
            return false;
        
        string key = to_string(index) + "," + to_string(target);
        if(dp.find(key) != dp.end())
            return dp[key];

        if(helper(arr, index+1, target-arr[index], dp)) {
            dp[key] = true;
            return true;
        }            

        if(helper(arr, index+1, target, dp)) {
            dp[key] = true;
            return true;
        }
        
        dp[key]= false;
        return false;
    }


    bool canPartition(vector<int>& nums) {
        if(nums.size() <= 1)
            return false;
        
        int sum = 0;
        for(auto it:nums)
            sum += it;
        
        if(sum % 2 != 0)
            return false;

        unordered_map<string, bool> dp;
        return helper(nums, 0, sum/2, dp);
    }
};
