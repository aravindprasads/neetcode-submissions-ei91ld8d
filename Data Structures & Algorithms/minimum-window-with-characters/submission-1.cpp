class Solution {
public:


    bool valid(unordered_map<char, int> hash_s, unordered_map<char, int> hash_t) {
        for(auto it:hash_t) {
            if(it.second > hash_s[it.first])
                return false;
        }
        return true;
    }

    unordered_map<char, int> createHash(string t) {
        unordered_map<char, int> hash;
        for(auto it:t) {
            hash[it]++;
        }
        return hash;
    }


    string minWindow(string s, string t) {
        if(t.length() == 0 || s.length()==0)
            return "";
        if(t.length() > s.length())
            return "";

        unordered_map<char, int> hash_t = createHash(t);
        unordered_map<char, int> hash_s;
        int ans = INT_MAX;

        int l=0, r=0;
        int st=-1, end=-1;        
        while(r < s.length()) {
            hash_s[s[r]]++;
            while(valid(hash_s, hash_t)) {
                if(ans >  r-l+1) {
                    st = l;
                    end = r;
                    ans = r-l+1;
                }
                hash_s[s[l]]--;
                if(hash_s[s[l]] == 0)
                    hash_s.erase(s[l]);
                l++;
            }
            r++;
        }
        string ans_;
        if(st == -1)
            return "";
        for(int i=st; i<=end; i++)
            ans_ += s[i];
        return ans_;
    }
};
