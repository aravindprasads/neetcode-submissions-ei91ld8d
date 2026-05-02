class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> hash;
        for(auto it:nums) {
            hash[it]++;
            if(hash[it] > 1)
                return true;
        }

        return false;
    }
};