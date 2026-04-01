class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int, int> kvmap;
        for(int i=0; i<nums.size(); i++) {
            if(kvmap.find(nums[i]) != kvmap.end()) {
                kvmap[nums[i]] += 1;
            }
            else {
                kvmap[nums[i]] = 1;
            }
        }
        multimap <int, int, greater<int>> valuemap;
        for (auto it : kvmap) {
            int key = it.first;
            int val = it.second;            
            // valuemap[val] = key;
            valuemap.insert(pair<int, int>(val, key));
        }
        vector <int> res;
        for (auto it : valuemap) {
            if(k > 0) {
                res.push_back(it.second);
                k--;
            }
        }
        return res;
    }
};
