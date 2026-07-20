class Solution {
public:

    void twoSum(vector<int>nums, int firstEle, vector<vector<int>>& ans, int st) {
        int i= st+1, j = nums.size()-1;

        while(i < j) {
            int sum = nums[i] + nums[j] + firstEle;
            if(sum == 0) {
                ans.push_back({firstEle, nums[i], nums[j]});
                i++;
                j--;
                while((i<j) && (nums[i] == nums[i-1])) {
                    i++;                        
                }
                while((i<j) && (nums[j] == nums[j+1])) {
                    j--;                        
                }
            } else if(sum > 0) {
                j--;
            } else {
                i++;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int i = 0;
        while(i < (nums.size()-2)) {
            if(i!=0 && (nums[i] == nums[i-1])) {
                i++;
                continue;
            }                        
            twoSum(nums, nums[i], ans, i);
            i++;
        }        
        return ans;
    }
};
