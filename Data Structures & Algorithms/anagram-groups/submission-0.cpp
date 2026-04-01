class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> copy = strs;
        for(int i=0; i<copy.size(); i++) {
            sort(copy[i].begin(), copy[i].end());
        }        
        unordered_map<string, vector<string>> map;
        for(int i=0; i<copy.size(); i++) {
            if(map.find(copy[i]) != map.end()) {
            vector<string> res = map[copy[i]];
            res.push_back(strs[i]);
            map[copy[i]] = res;
            }
            else
            {
            vector<string> res;
            res.push_back(strs[i]);
            map[copy[i]] = res;
            }
        }
        vector<vector<string>> answer;
        for(auto it : map) {
            answer.push_back(it.second);
        }
        return answer;
    }
};