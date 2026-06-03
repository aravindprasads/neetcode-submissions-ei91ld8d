class Solution {
public:

// hash ->  val, index

    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> hash;
        int ind = 0;
        for(auto it:nums) {
            hash[it].push_back(ind);
            ind++;
        }        

        ind = 0;
        for(auto it:nums) {
            int val = target - it;
            int v_ind = ind;

            if(hash.find(val) != hash.end()) {
                auto vec = hash[val];
                for(auto it1:vec) {
                    if(it1 != v_ind) {
                        vector <int> ans;
                        ans.push_back(it1);
                        ans.push_back(v_ind);
                        sort(ans.begin(), ans.end());
                        return ans;
                    }
                }
            }
            ind++;            
        }
        return vector<int>{};
    }
};
