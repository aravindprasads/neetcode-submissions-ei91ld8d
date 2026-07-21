class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length () > s2.length())
            return false;
        if(s1 == "") {
            if(s2 == "")
                return true;
            return false;
        }
        
        int i=0, j=s1.length()-1;
        unordered_map<char, int> h1, h2;

        for(int i=0; i<s1.length(); i++) {
            h1[s1[i]]++;
        }

        for(int i=0; i<s1.length(); i++) {
            h2[s2[i]]++;
        }
        if(h1 == h2)
            return true;

        j++;        
        while(j < s2.length()) {
            h2[s2[j]]++;
            h2[s2[i]]--;
            if(h2[s2[i]] == 0)
                h2.erase(s2[i]);

            if(h1 ==  h2)
                return true;

            i++;
            j++;            
        }

        return false;
        
    }
};
