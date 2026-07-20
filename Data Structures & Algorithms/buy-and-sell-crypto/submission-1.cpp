class Solution {
public:
    int maxProfit(vector<int>& arr) {
        if(arr.size() <= 1)
            return 0;
        int mini = arr[0];
        int profit = 0;
        for(auto it:arr) {
            mini = min(mini, it);
            profit = max(profit, it-mini);
        }
        return profit;
    }
};
