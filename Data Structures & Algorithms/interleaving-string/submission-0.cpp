class Solution {
public:

    bool helper(string s1, string s2, string s3, int i1, int i2, int i3,
                unordered_map<string, bool>& dp) {

        if((i3 == s3.size()) && (i1 == s1.size()) && (i2 == s2.size()))
            return true;
        
        if(i3 == s3.size())
            return false;

        string key = to_string(i1) + "," + to_string(i2) + "," + to_string(i3);
        if(dp.find(key) != dp.end())
            return dp[key];

        if((i1 < s1.size()) && (s3[i3] == s1[i1])) {
            if(helper(s1, s2, s3, i1+1, i2, i3+1, dp)) {
                dp[key] = true;
                return true;
            }
        }

        if((i2 < s2.size()) && (s3[i3] == s2[i2])) {
            if(helper(s1, s2, s3, i1, i2+1, i3+1, dp)) {
                dp[key] = true;
                return true;
            }
        }
        
        dp[key] = false;
        return false;
    }

    bool isInterleave(string s1, string s2, string s3) {
        unordered_map<string, bool> dp;
        return helper(s1, s2, s3, 0, 0, 0, dp);
    }
};
