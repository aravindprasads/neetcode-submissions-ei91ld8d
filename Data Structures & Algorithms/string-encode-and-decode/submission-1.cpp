class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for (int i=0; i<strs.size(); i++) {
            string str = strs[i];
            res += to_string(str.length())+"#"+str;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        string number = "";
        for (int i=0; i<s.length(); i++) {
            if(s[i] != '#') {
            number += s[i];
            }
            else {
            cout<<"number"<<number<<endl;
            int no = atoi(number.c_str());
            i += 1;
            string res_str;
            for(int j=0; j<no; j++) {
                res_str += s[i];
                i++;
            }
            res.push_back(res_str);
            number = "";
            i--;
            }
        }
        return res;
    }
};
