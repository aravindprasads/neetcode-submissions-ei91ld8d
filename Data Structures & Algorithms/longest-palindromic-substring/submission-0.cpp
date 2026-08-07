class Solution {
public:

    tuple<int, int, int> helper(int index, string s) {
        
        int l = index, ll = index;
        int r = index, rr = index;
        int maxi = 0;

        while((l>=0) && (r <s.length()) && (s[l] == s[r])) {            
            if(maxi < (r-l+1)) {
                maxi = r-l+1;
                ll = l;
                rr = r;            
            }
            l--;
            r++;        
        }

        l = index;
        r = index+1;
        while((l>=0) && (r < s.length()) && (s[l] == s[r])) {                        
            if(maxi < (r-l+1)) {
                maxi = r-l+1;
                ll = l;
                rr = r;
            }
            l--;
            r++;
        }

        cout<<index<<" "<<maxi<<" "<<ll<<" "<<rr<<endl;
        return {maxi, ll, rr};
    }

    string longestPalindrome(string s) {
        int maxi = 0, maxl=0, l=0, r=0, ll=0, rr=0;        

        for(int i=0; i<s.length(); i++) {
            auto [maxl, l, r] = helper(i, s);
            if (maxi < maxl) {
                ll = l;
                rr = r;
                maxi = maxl;
            }
        }

        string ans="";
        for(int i=ll; i<=rr; i++)
            ans += s[i];

        return ans;
    }
};