class Solution {
public:

    int bs(vector<int> arr, int low, int high) {
        int ans = arr[0];

        while(low <= high) {
            int mid = (high + low)/2;
            
            // left sorted
            if(arr[low] <= arr[mid]) {
                ans =  min(ans, arr[low]);
                low = mid+1; // go right
            } else {
                ans = min(ans, arr[mid]);
                high = mid-1; // go left
            }
        }    
        return ans;
    }

    int findMin(vector<int> &nums) {
        if(nums.size() == 0)
            return -1;
        
        if(nums[0] <= nums[nums.size()-1])
            return nums[0];
        
        return bs(nums, 0, nums.size()-1);
    }
};
