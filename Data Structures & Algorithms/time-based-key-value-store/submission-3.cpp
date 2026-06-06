class TimeMap {
public:

    // vector<int> vec;
    unordered_map<string, vector<int>> lookup;
    map<string, string> hash;

    int binSearch(int low, int high, int target, vector<int> arr) {
        int ans = -1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(arr[mid] <= target) {
                ans = arr[mid];
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return ans;
    }

    TimeMap() {
        return;    
    }
    
    void set(string key, string value, int timestamp) {
        // vec.push_back(timestamp);
        lookup[key].push_back(timestamp);
        string _key = to_string(timestamp)+","+key;
        // cout<<_key<<endl;
        hash[_key] = value;
        cout<<"SET "<<timestamp << " " << key<<" "<<value<<endl;
    }
    
    string get(string key, int timestamp) {
        cout<<"GET "<<timestamp << " " << key<<endl;
        // if(vec.size() == 0)
        //     return "";
        if(lookup.find(key) == lookup.end())
            return "";
        int index = binSearch(0, lookup[key].size()-1, timestamp, lookup[key]);
        cout<<"INDEX "<<index<<endl;     
        if(index == -1)
            return "";   
        string _key = to_string(index) + "," + key;
        // cout<<_key<<endl;
        if(hash.find(_key) != hash.end()) {
            cout<<"key found"<<endl;
            return hash[_key];
        }
        cout<<"key not found"<<endl;
        return "";
    }
};
