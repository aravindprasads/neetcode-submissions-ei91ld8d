class Solution {
public:

    int search(int no, unordered_set<int>& hash) {
        int cnt = 1;
        no++;
        while(hash.find(no) != hash.end()) {
            cnt++;
            no++;
        }
        return cnt;
    }

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        
        for(auto it:nums)
            hash.insert(it);

        int maxi = 0;
        for(auto it:nums) {
            int no = it-1;
            if(hash.find(no) != hash.end())
                continue;
            maxi = max(maxi, search(it, hash));
        }
        
        return maxi;
    }
};
