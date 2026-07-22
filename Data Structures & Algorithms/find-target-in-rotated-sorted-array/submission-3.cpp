class Solution {
public:

    int bs(vector<int>arr, int target, int low, int high) {
        while(low <= high) {
            int mid = (high + low)/2;
            if(arr[mid] == target)
                return mid;
            //left sorted
            if(arr[low] <= arr[mid]) {
                if((arr[low] <= target) && (target <= arr[mid])) {
                    high = mid-1;                    
                }
                else {
                    low = mid+1;
                }
            } else { // right sorted
                if((arr[mid] <= target) && (target <= arr[high])) {
                    low = mid+1;
                } else {
                    high = mid-1;
                }
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        return bs(nums, target, 0, nums.size()-1);
    }
};
