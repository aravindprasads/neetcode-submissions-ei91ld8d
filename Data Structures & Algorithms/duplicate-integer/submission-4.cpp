class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // unordered_map<int, bool> hash;
        unordered_set<int> mset;
        for(auto it:nums) {
            if(mset.find(it) != mset.end())
                return true;
            // hash[it] = true;
            mset.insert(it);
        }
        return false;        
    }
};