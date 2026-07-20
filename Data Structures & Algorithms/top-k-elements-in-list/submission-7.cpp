class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> hash;
        for(auto it:nums) {
            hash[it]++;
        }

        priority_queue<tuple<int, int>, vector<tuple<int, int>>, less<tuple<int, int>>> heap;
        for(auto it:hash) {
            heap.push({it.second, it.first});
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
