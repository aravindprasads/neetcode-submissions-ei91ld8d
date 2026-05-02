class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> h1, h2;
        for(auto it:s) {
            h1[it]++;
        }
        for(auto it:t) {
            h2[it]++;
        }
        if(h1 == h2)
            return true;
        return false;
    }
};
