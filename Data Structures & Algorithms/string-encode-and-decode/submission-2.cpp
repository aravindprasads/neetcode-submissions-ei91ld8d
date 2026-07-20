class Solution {
public:

    string encode(vector<string>& strs) {        
        string ans = "";
        for(auto it:strs) {
            int len = it.length();
            ans += to_string(len) + "#" + it; 
        }
        cout<<ans<<endl;
        return ans;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> ans;
        while (i < s.length()) {
            cout<<"i "<<i<<endl;
            string nums = "";
            while(s[i] != '#') {
                nums += s[i];
                i++;
            }
            int numi = stoi(nums);

            cout<<"# "<<i<<endl;
            i++;
            cout<<numi<<endl;

            string a_str = "";
            while(numi) {
                a_str += s[i]; 
                numi--;
                i++;
            }    
            ans.push_back(a_str);            
        }

        return ans;
    }
};
