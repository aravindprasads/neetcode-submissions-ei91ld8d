/*
hash - number to index 
same number - value part to be an array

search:
find index not equal to my current index 

*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> hash;
        
        for(int i=0; i<nums.size(); i++) {
            hash[nums[i]].push_back(i);            
        }

        for(int i=0; i<nums.size(); i++) {
            int diff = target-nums[i];
            if(hash.find(diff) != hash.end()) {                
                vector<int>vals = hash[diff];
                for(auto it:vals) {
                    if(i != it) {
                        if(i < it)
                            return vector<int>{i, it};
                        else
                            return vector<int>{it, i};                            
                    }
                }
            }
        }
        return vector<int>{};
    }
};
