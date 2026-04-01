class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int total = 0;
        int count_zeros=0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                if(total == 0)
                    total= nums[i];
                else
                    total *= nums[i];
            }
            else
                count_zeros++;
        }
        vector<int>res;
        if(count_zeros > 1) {
            for(int i=0; i<nums.size(); i++)
                res.push_back(0);
            return res;
        }
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] != 0) {
                if(count_zeros)
                    res.push_back(0);
                else
                    res.push_back(total/nums[i]);
            }
            else {
                res.push_back(total);
            }         
        }
        return res;
    }
};
