class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        for(auto it:nums) {
            if(hash.find(it) != hash.end())
                return true;
            hash.insert(it);
        }
        return false;
    }
};