class Solution {
public:

    bool valid(unordered_map<char, int> h1, unordered_map<char, int> h2) {
        for(auto it:h2) {
            char ch = it.first;
            int cnt = it.second;
            if(h1.find(ch) == h1.end())
                return false;                        
            if(cnt > h1[ch])
                return false;                 
        }
        return true;
    }

    string minWindow(string s, string t) {

        int l=0, r=0;

        unordered_map<char, int> h1, h2;

        for(auto it:t)
            h2[it]++;

        int st=-1,end=-1;
        int mini = INT_MAX;
        while(r < s.length()) {
            h1[s[r]]++;            
            while(valid(h1, h2)) {                
                if(mini > (r-l+1)) {
                    mini = r-l+1;
                    st = l;
                    end = r;
                }
                h1[s[l]]--;
                if(h1[s[l]] == 0)
                    h1.erase(s[l]);
                l++;
            }
            r++;
        }

        if(st == -1)
            return "";

        string ans;
        for(int i=st; i<=end; i++)
            ans += s[i];
        return ans;
    }
};
