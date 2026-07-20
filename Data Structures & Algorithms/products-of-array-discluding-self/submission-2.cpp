class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {        
        if(nums.size() <= 1)
            return vector<int>{nums[0]};

        int cnt = 0;
        for(auto it:nums) {
            if(it == 0)
                cnt++;
        }

        vector<int> ans;
        
        if(cnt > 1) {
            for(auto it:nums)
                ans.push_back(0);
                return ans;                
        }

        vector<int>l;
        l.push_back(nums[0]);
        
        int prod = ((nums[0] == 0) ? 1 : nums[0]);
        for(int i=1; i < nums.size(); i++) {
            if(nums[i] == 0)
                continue;
            prod = prod * nums[i];
            l.push_back(prod);        
        }

        vector<int> r(nums.size(), 0);
        r[nums.size()-1] = nums[nums.size()-1];
        
        prod = ((nums[nums.size()-1] == 0) ? 1 : nums[nums.size()-1]);
        
        for(int j=nums.size()-2; j>=0; j--) {
            if(nums[j] == 0)
                continue;
            prod = prod * nums[j];
            r[j] = prod;        
        }

        for(int i=0; i<nums.size(); i++) {
            if(cnt == 1 && nums[i] != 0)
                ans.push_back(0);
            else if(i == 0)
                ans.push_back(r[i+1]);
            else if(i == nums.size()-1)
                ans.push_back(l[i-1]);
            else
                ans.push_back(l[i-1] * r[i+1]);
        }

        return ans;
    }
};


// 1 2 4 6

// L  1  2   8   48
// R  48 48  24  6
