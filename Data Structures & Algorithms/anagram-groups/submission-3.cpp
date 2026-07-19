class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;

        for(auto nstr:strs) {
            string bstr = nstr;
            sort(nstr.begin(), nstr.end());
            hash[nstr].push_back(bstr);
        } 
        
        vector<vector<string>> ans;
        for(auto it:hash) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
