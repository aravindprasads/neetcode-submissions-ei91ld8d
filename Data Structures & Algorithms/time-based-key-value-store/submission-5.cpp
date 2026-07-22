class TimeMap {
public:

    unordered_map<string, vector<pair<int, string>>> hash;
    
    TimeMap() {
        return;    
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp, value});        
    }
    
    string bs(vector<pair<int, string>> list, int target, int low, int high) {
        string ans = "";
        while(low <= high) {
            int mid = (high+low)/2;
            auto [time, val] = list[mid];
            if(time == target)
                return val;
            
            if(time > target) {
                high = mid-1;
            } else {
                ans = val;
                low = mid+1;
            }
        }
        return ans;
    }

    string get(string key, int timestamp) {
        if(hash.find(key) == hash.end())
            return "";
        
        vector<pair<int, string>> list = hash[key];
        if(list.size() == 0)
            return "";

        return bs(list, timestamp, 0, list.size()-1);        
    }
};
