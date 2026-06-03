class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;

        unordered_map<char, int> hash;
        for(auto it:s) {
            hash[it]++;
        }

        for(auto it:t) {
            if(hash.find(it) == hash.end())
                return false;
            hash[it]--;
            if(hash[it] == 0)
                hash.erase(it);
        }

        return true;        
    }
};
