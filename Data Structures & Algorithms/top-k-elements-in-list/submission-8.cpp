class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> hash;
        for(auto it:nums) {
            hash[it]++;
        }

        priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int>>> heap;
        for(auto it:hash) {
            if(heap.size() < k)
                heap.push({it.second, it.first});
            else {
                auto [freq, val] = heap.top();
                if(it.second > freq) {
                    heap.pop();
                    heap.push({it.second, it.first});                    
                }
            }
        }

        vector<int> ans;
        while(k && !heap.empty()) {
            auto [freq, val] = heap.top();
            ans.push_back(val);
            heap.pop();
            k--;
        }
        return ans;
    }
};
