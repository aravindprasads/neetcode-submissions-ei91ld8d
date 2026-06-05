class Solution {
public:

    int binarySearch(int low, int high, int target, vector<int> arr) {
        while(low <= high) {
            int mid = (low + high)/2;
            if(arr[mid] == target)
                return mid;
            if(arr[mid] > target)
                high = mid-1;
            else
                low = mid+1;
        }
        return -1;
    }


    int search(vector<int>& nums, int target) {
        return binarySearch(0, nums.size()-1, target, nums);
    }
};
