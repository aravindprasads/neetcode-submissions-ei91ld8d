class Solution {
public:

    int findMax(unordered_map<char, int> hash) {
        int maxi = 0;
        for(auto it:hash) {
            maxi = max(maxi, it.second);
        }
        return maxi;
    }


    int characterReplacement(string s, int k) {
        if(s.length() <= 1)
            return s.length();
        int l=0,r=0;
        unordered_map<char, int> hash;
        int maxFreq=0, maxi=0;

        while(r < s.length()) {
            hash[s[r]]++;
            maxFreq = max(maxFreq, hash[s[r]]);

            while(((r-l+1) - maxFreq) > k) {
                hash[s[l]]--;
                if(hash[s[l]] == 0)
                    hash.erase(s[l]);
                maxFreq = findMax(hash);
                l++;
            }

            maxi = max(maxi, r-l+1);
            r++;
        }
        return maxi;
    }
};
