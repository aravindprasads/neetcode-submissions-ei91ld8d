class Solution {
public:

    int getVal(int val, vector<int> arr) {
        int ans = 0;
        for(auto it:arr) {
            int div = it/val;
            ans += div;
            if((val*div) < it)
                ans++;
        }
        return ans;
    }



    int binSearch(int low, int high, vector<int>arr, int target) {
        int ans = high;
        while(low <= high) {
            int mid = (low + high)/2;
            int val = getVal(mid, arr);
            if(val <= target) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }

    void findMinMax(vector<int> arr, int& mini, int& maxi) {
        for(auto it:arr) {
            mini = min(mini, it);
            maxi = max(maxi, it);
        }
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int mini = INT_MAX, maxi = INT_MIN;
        findMinMax(piles, mini, maxi);        
        return binSearch(1, maxi, piles, h);
    }
};
