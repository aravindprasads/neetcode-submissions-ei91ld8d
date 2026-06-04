class Solution {
public:

    void find2Sum(vector<int>nums, int val, int index, vector<vector<int>>& ans) {
        int target = val * -1;

        int i = index+1, j = nums.size()-1;
        while(i < j) {
            int sum = nums[i] + nums[j];
            if(sum == target) {
                vector<int>n_ans;
                n_ans.push_back(val);
                n_ans.push_back(nums[i]);
                n_ans.push_back(nums[j]);
                ans.push_back(n_ans);

                i++;
                while(i < j) {
                    if(nums[i] == nums[i-1])
                        i++;
                    else
                        break;
                }
                if (i >= j)
                    break;

                j--;
                while(i < j) {
                    if(nums[j] == nums[j+1])
                        j--;
                    else
                        break;
                }                
            } else if (sum > target) {
                j--;
            } else {
                i++;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for(int i=0; i<nums.size()-2; i++) {
            if(i!=0 && (nums[i] == nums[i-1]))
                continue;
            find2Sum(nums, nums[i], i, ans);
        }
        return ans;        
    }
};
