class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        priority_queue<pair<int, int>, vector<pair<int, int>>> heap;

        for(int i=0; i<k; i++)
            heap.push({nums[i], i});
        
        vector<int> ans;        
        ans.push_back(heap.top().first);

        int index = 1;
        for(int i=k; i<nums.size(); i++) {
            heap.push({nums[i], i});

            while(heap.top().second < index) {
                cout<<heap.top().second<<" "<<i<<endl;
                heap.pop();
            }
            
            ans.push_back(heap.top().first);
            index++;            
        }
        return ans;        
    }
};
