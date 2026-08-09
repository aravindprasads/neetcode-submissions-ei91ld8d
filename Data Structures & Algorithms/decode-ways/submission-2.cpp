/*
12345

fn(str, index) {
    for index - go till end
        ch += str[index]
        if(!vaid(ch))
            return 0    
        cnt += fn(str, index+i)


}
*/

bool valid(string s, unordered_set<string> hash) {
    if(hash.find(s) != hash.end())
        return true;
    return false;
}

int helper(string s, int index, unordered_set<string> hash, unordered_map<int, int>& mmap) {
    
    if(index >= s.length()) {
        return 1;
    }

    if(mmap.find(index) != mmap.end())
        return mmap[index];

    string new_s= "";
    int cnt = 0;

    for(int i=index; i<s.length(); i++) {
        new_s += s[i];
        if(!valid(new_s, hash))
            break;        
        cnt += helper(s, i+1, hash, mmap);
    }

    mmap[index] = cnt;
    return cnt;
}

class Solution {
public:
    int numDecodings(string s) {
        
        unordered_set<string> hash;
        for(int i=1; i<=26; i++)
            hash.insert(to_string(i));

        unordered_map<int, int> mmap;
        return helper(s, 0, hash, mmap);
    }
};
