class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> hash;
        for(auto it:nums) {
            if(hash.find(it) != hash.end())
                return true;
            hash[it] = true;
        }
        return false;        
    }
};