class Solution {
public:

// r -> 0 to length(s):
//     add s[r] to hash
//     maxi = max(maxi, hash[s[r]])
//     while((r-l+1) - maxi > k) {
//         remove s[l] from hash
//         recaulctae max through hash
//     }
//     ans = max(ans, r-l+1);
//     r++;


    int reCalc(unordered_map<char, int> hash) {
        int maxi = 0;
        for(auto it: hash) {
            maxi = max(maxi, it.second);            
        }
        return maxi;
    }

    int characterReplacement(string s, int k) {
        int l=0, r=0;
        int ans = 0;
        int maxFreq = 0;
        unordered_map<char, int> hash;

        while(r < s.length()) {
            hash[s[r]]++;
            maxFreq = max(maxFreq, hash[s[r]]);

            while(((r-l+1) - maxFreq) > k) {
                hash[s[l]]--;                
                if(hash[s[l]] == 0)
                    hash.erase(s[l]);
                l++;
                maxFreq = reCalc(hash);
            }
            ans = max (ans, r-l+1);            
            r++;
        }
        return ans;
    }
};
