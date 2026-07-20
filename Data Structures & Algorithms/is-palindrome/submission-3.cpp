class Solution {
public:

    bool isAlpha(char c) {
        int asc = int(c);
        if((asc >= int('a')) && asc<=int('z'))
            return true;
        if((asc >= int('A')) && asc<=int('Z'))
            return true;
        if((asc >= int('0')) && asc<=int('9'))
            return true;
        return false;    
    }

    bool isPalindrome(string s) {
        if(s.length() <= 1)
            return true;
        int i=0, j = s.length()-1;
        bool rc = true;
        while(i <= j) {
            if(!isAlpha(s[i])) {
                i++;
                continue;
            }
            if(!isAlpha(s[j])){
                j--;
                continue;
            }                
            if(tolower(s[i]) != tolower(s[j])) {
                rc = false;
                break;
            }
            i++;
            j--;                
        }
        return rc;
    }
};
