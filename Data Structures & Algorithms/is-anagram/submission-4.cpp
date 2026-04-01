class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        unordered_map <char, int>mapS,mapT;
        for(int i=0; i<s.length(); i++) {            
            if(mapS.find(s[i]) != mapS.end())
                mapS[s[i]] += 1;
            else
                mapS[s[i]] = 1;
            if(mapT.find(t[i]) != mapT.end())
                mapT[t[i]] += 1;
            else
                mapT[t[i]] = 1; 
        }
        for(auto it : mapS) {
            int key = it.first;
            int val = it.second;
            if(mapT[key] != val)
                return false;
        }        
    }
};
