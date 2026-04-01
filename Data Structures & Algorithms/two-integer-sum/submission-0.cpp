class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> map;
        for(int i=0; i <nums.size(); i++) {
            map[nums[i]] = i;
        }
        vector <int> res;
        for(int i=0; i <nums.size()-1; i++) {
            int val = target-nums[i];
            if(map.find(val) != map.end()) {
                if(i != map[val]) {                    
                    res.push_back(i);
                    res.push_back(map[val]);
                    return res;
                }
            }
        }
        return res;        
    }
};
