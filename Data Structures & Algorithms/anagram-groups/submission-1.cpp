class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <vector<int>,vector<string>> map;
        for(int i=0; i<strs.size(); i++) {
            string str = strs[i];
            vector<int> count_arr(26, 0);
            for(int i=0; i<str.length(); i++) {
            int pos = str[i]-'a';
            count_arr[pos] += 1;
            }
            if(map.find(count_arr) != map.end()) {
            vector <string> res = map[count_arr];
            res.push_back(str);
            map[count_arr] = res;
            }
            else {
            vector <string> res;
            res.push_back(str);
            map[count_arr] = res;
            }
        }
        vector<vector<string>> answer;
        for(auto it : map) {
            answer.push_back(it.second);
        }
        return answer;        
    }
};