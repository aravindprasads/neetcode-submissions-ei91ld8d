class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1)
            return s.length();

        int r=0, l=0;
        int maxi = INT_MIN;
        
        unordered_set<char> hash;
        while(r < s.length()) {
            while(hash.find(s[r]) != hash.end()) {
                hash.erase(s[l]);
                l++;
            }
            hash.insert(s[r]);
            maxi = max(maxi, r-l+1);
            r++;
        }
        return maxi;
    }
};
