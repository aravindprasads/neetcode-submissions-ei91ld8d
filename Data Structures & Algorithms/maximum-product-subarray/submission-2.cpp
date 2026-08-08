class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int prod = 1;

        for(int i=0; i<nums.size(); i++) {
            if(prod == 0)
                prod = nums[i];
            else
                prod = prod * nums[i];
            maxi = max(maxi, prod);
            maxi = max(maxi, nums[i]);
        }
        prod = 1;
        for(int j=nums.size()-1; j >= 0; j--) {
            if(prod == 0)
                prod = nums[j];
            else
                prod = prod * nums[j];
            maxi = max(maxi, prod);
            maxi = max(maxi, nums[j]);
        }
        
        return maxi;
    }
};
