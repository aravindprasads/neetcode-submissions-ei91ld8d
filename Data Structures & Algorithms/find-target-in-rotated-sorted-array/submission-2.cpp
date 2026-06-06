class Solution {
public:

    int binSearch(int low, int high, int target, vector<int>arr) {
        while(low <= high) {
            int mid = (low + high)/2;
            if(arr[mid] == target)
                return mid;
            if(arr[low] <= arr[mid]) {
                if((arr[low]<=target) && (target <= arr[mid]))
                    high = mid-1;
                else
                    low = mid+1;
            } else {
                if((arr[mid]<=target) && (target <= arr[high]))
                    low = mid+1;
                else
                    high = mid-1;
            }                                 
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return binSearch(0, nums.size()-1, target, nums);
    }
};
