class Solution {
public:

    int binSearch(int low, int high, vector<int> arr) {
        int ans = INT_MAX;
        while(low <= high) {
            int mid = low + (high-low)/2;
            if(arr[low] <= arr[mid]) {
                ans = min(ans, arr[low]);
                low = mid+1;
            } else {
                ans = min(ans, arr[mid]);
                high = mid-1; 
            }
        }
        return ans;
    }

    int findMin(vector<int> &nums) {
        return binSearch(0, nums.size()-1, nums);
    }
};
