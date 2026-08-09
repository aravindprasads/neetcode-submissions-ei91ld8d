class Solution {
public:

    bool helper(string s, int index, unordered_set<string> dic, 
                unordered_map<int, bool>& dp) {
        if(index >= s.length())
            return true;
        
        if(dp.find(index) != dp.end())
            return dp[index];        

        string new_s = "";
        for(int i=index; i<s.length(); i++) {
            new_s += s[i];            
            if(dic.find(new_s) != dic.end()) {                
                if(helper(s, i+1, dic, dp)) {
                    dp[index] = true;
                    return true;
                }
            }
        }
        dp[index] = false;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_map<int, bool> dp;
        unordered_set<string> dic;
        for(auto it:wordDict)
            dic.insert(it);

        return(helper(s, 0, dic, dp));
    }
};
