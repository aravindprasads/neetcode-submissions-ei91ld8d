class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.length() == 0)
            return false;

        if(s1.length() > s2.length())
            return false;

        unordered_map<char, int> hash_s1, hash_s2;
        for(auto it:s1) {
            hash_s1[it]++;
        }

        for(int i=0; i<s1.length(); i++)
            hash_s2[s2[i]]++;

        if(hash_s1 == hash_s2)
            return true;
        
        int ind = 0;
        for(int i=s1.length(); i<s2.length(); i++) {
            hash_s2[s2[i]]++;
            hash_s2[s2[ind]]--;
            if(hash_s2[s2[ind]] == 0)
                hash_s2.erase(s2[ind]);
            if(hash_s1 == hash_s2)
                return true;
            ind++;
        }

        return false;
        
    }
};
