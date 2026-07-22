/*
Binary search 
space
1 .. N 
(maxValue of array)

min val satisfying the condition

BinSearch
value satisfies -> choose it and go left
*/


class Solution {
public:

    bool check(vector<int>arr, int val, int target) {
        int ch = 0;
        for(auto it:arr) {
            ch += it/val;
            if(it % val != 0)
                ch++;
        }
        return ((ch <= target) ? true : false);
    }

    int bs(vector<int>arr, int target, int low, int high) {
        int ans = high;
        while(low <= high) {
            int mid = (high+low)/2;
            if(check(arr, mid, target)) {
                ans = mid;
                high= mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        if(h < piles.size())
            return -1;
        
        int maxi = INT_MIN;
        for(auto it:piles){
            maxi = max(maxi, it);
        }

        return bs(piles, h, 1, maxi);
    }
};
