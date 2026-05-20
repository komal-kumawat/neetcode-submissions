class TimeMap {
public:
    map<string,vector<pair<int , string>>>hash;
    TimeMap() {     
    }
    
    void set(string key, string value, int timestamp) {
        hash[key].push_back({timestamp , value});
        
    }
    
    string get(string key, int timestamp) {
        if(hash.find(key)==hash.end()) return "";
        vector<pair<int,string>>&arr = hash[key];
        int low = 0 , high = arr.size()-1;
        string ans = "";
        while(low<=high){
            int mid = low+(high-low)/2;
            int curr = arr[mid].first;
            if(curr<=timestamp){
                ans = arr[mid].second;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return ans;

        
    }
};
