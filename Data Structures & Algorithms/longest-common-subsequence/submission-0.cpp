class Solution {
public:

    int helper(string s1, string s2, int l1, int l2, unordered_map<string, int>& dp) {

        if(s1 == "" || s2 == "")
            return 0;
        if((l1 >= s1.length()) || (l2 >=s2.length()))
            return 0;
        
        string key = to_string(l1) + "," + to_string(l2);
        if(dp.find(key) != dp.end())
            return dp[key];

        if(s1[l1] == s2[l2])
            return 1 + helper(s1, s2, l1+1, l2+1, dp);
        
        int p1 = helper(s1, s2, l1+1, l2, dp);
        int p2 = helper(s1, s2, l1, l2+1, dp);

        dp[key] = max(p1,p2);
        return dp[key];
    }

    int longestCommonSubsequence(string text1, string text2) {
        unordered_map<string, int> dp;
        return helper(text1, text2, 0, 0, dp);
    }
};
