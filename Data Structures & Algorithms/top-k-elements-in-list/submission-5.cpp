class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        for(auto it:nums) {
            hash[it]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> heap;

        for(auto it:hash) {
            cout<<k<<endl;
            if(k == 0) {
                auto [freq, val] = heap.top();
                if(it.second > freq) {
                    cout<<"cond"<<endl;
                    cout<<it.first<<"   "<<it.second<<endl;
                    cout<<freq<<endl;
                    heap.push({it.second, it.first});
                    heap.pop();
                }
            } else {
                k--;
                heap.push({it.second, it.first});
            }                       
        }
        
        vector<int> ans;
        while(!heap.empty()) {
            auto [freq, val] = heap.top();
           
            ans.push_back(val);
            heap.pop();
        }

        return ans;
    }
};
