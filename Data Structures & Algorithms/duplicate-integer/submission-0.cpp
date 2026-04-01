class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map <int, int> map;
        for(int i=0; i<nums.size(); i++) {
            auto it =  map.find(nums[i]);
            if (it != map.end()) 
                return true;
            map[nums[i]] = 1;
        }
        return false;
    }
};
