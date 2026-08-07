class Solution {
public:

    int helper(int index, string s) {
        
        int l = index, ll = index;
        int r = index, rr = index;
        int maxi = 0;
        int cnt = 0;

        while((l>=0) && (r <s.length()) && (s[l] == s[r])) {            
            cnt++;
            l--;
            r++;        
        }

        l = index;
        r = index+1;
        while((l>=0) && (r < s.length()) && (s[l] == s[r])) {                        
            cnt++;
            l--;
            r++;
        }

        // cout<<index<<" "<<maxi<<" "<<ll<<" "<<rr<<endl;
        return cnt;
    }

    int countSubstrings(string s) {
        int cnt = 0;
        for(int i=0; i<s.length(); i++)
            cnt += helper(i, s);        
        return cnt;
    }
};
