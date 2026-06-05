class Solution {
public:

    bool isAlpha(char c) {
        if((int(c) >= int('a')) && (int(c) <= int ('z')))
            return true;
        if((int(c) >= int('A')) && (int(c) <= int ('Z')))
            return true;
        if((int(c) >= int('0')) && (int(c) <= int ('9')))
            return true;
        return false;
    }


    bool isPalindrome(string s) {
        cout<<s.length()<<endl;
        if(s.length() <= 1)
            return true;

        int i=0, j=s.length()-1;

        while(i<j) {
            while((i<j) && !isAlpha(s[i])) {
                i++;
                continue;
            }
            if(i >= j)
                break;
            while(!isAlpha(s[j])) {
                j--;
                continue;
            }
            if(i >= j)
                break;
            cout<<i<<" "<<j<<endl;
            cout<<tolower(s[i])<<" "<<tolower(s[j])<<endl;

            if(tolower(s[i]) != tolower(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};
