class Solution {
public:

    unordered_map<int, int> build_hash(string s) {
        unordered_map<int, int> hash;
        for(auto it:s) {
            hash[it]++;
        }
        return hash;
    }

    bool check_hash(unordered_map<int, int>hash, string s) {
        for(auto it: s) {
            if(hash.find(it) == hash.end())
                return false;
            hash[it]--;
            if(hash[it] == 0)
                hash.erase(it);
        }
        if(hash.size() == 0)
            return true;
        return false;
    }

    bool isAnagram(string s, string t) {
        unordered_map<int, int> hash;
        hash = build_hash(s);
        return check_hash(hash, t);        
    }
};
