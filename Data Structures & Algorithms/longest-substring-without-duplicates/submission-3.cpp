class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1)
            return s.length();

        int r=0, l=0;
        int maxi = INT_MIN;

        unordered_map<char, int> hash;
        while(r < s.length()) {
            if(hash.find(s[r]) != hash.end()) {
                int index = hash[s[r]];
                if(l<=index && index<=r)
                    l = hash[s[r]]+1;                
            }
            hash[s[r]] = r;
            maxi = max(maxi, r-l+1);
            r++;
        }
        return maxi;
    }
};
