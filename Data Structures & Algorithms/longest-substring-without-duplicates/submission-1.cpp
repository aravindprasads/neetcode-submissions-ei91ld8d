class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> hash;
        int l=0, r=0;
        int maxi = 0;

        while(r < s.length()) {
            if(hash.find(s[r]) == hash.end()) {
                hash[s[r]] = r;
            } else {
                int pos = hash[s[r]];
                if(pos>=l) {
                    l = pos+1;
                    hash[s[r]] = r;
                } else {
                    hash[s[r]] = r;
                }
            }            
            maxi = max(maxi, r-l+1);
            r++;
        }
        return maxi;
    }
};
