/*
if(t[x] matches s[x])
  t[x+1], s[x+1]

t[x+1], s[x]
*/

class Solution {
public:

    int helper(string s, string t, int i1, int i2, unordered_map<string, int>& dp) {
        if(i2 == t.size())
            return 1;
        
        if(i1 == s.size())
            return 0;

        string key = to_string(i1) + "," + to_string(i2);
        if(dp.find(key) != dp.end())
            return dp[key];

        int cnt = 0;
        if(s[i1] == t[i2])
            cnt = helper(s, t, i1+1, i2+1, dp);

        cnt += helper(s, t, i1+1, i2, dp);

        dp[key] = cnt;
        return cnt;
    }

    int numDistinct(string s, string t) {
        unordered_map<string, int> dp;
        return helper(s, t, 0, 0, dp);
    }
};
