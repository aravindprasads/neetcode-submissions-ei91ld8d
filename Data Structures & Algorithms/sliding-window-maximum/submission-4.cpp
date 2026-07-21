class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        if(nums.size() == 0)
            return ans;
        if(nums.size() == 1)
            return vector<int>{nums[0]};
        
        priority_queue<pair<int, int>> heap;

        for(int i=0; i<k; i++) {
            heap.push({nums[i], i});
        }
        
        ans.push_back(heap.top().first);

        int r=k, l=0;
        while(r < nums.size()) {
            heap.push({nums[r], r});            
            l++;
                        
            while(!heap.empty() && (heap.top().second < l) || (heap.top().second > r)) {
                heap.pop();            
            }
            ans.push_back(heap.top().first);
            r++;
        }
        return ans;                
    }
};
