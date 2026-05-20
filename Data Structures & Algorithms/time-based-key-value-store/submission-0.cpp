class TimeMap {
public:
    map<string,map<int , string>>hash;
    TimeMap() {     
    }
    
    void set(string key, string value, int timestamp) {
        hash[key][timestamp] = value;
        
    }
    
    string get(string key, int timestamp) {
        
        for(int i=timestamp;i>=0;i--){
            if(hash[key].find(i)!=hash[key].end()) return hash[key][i];

        }
        return "";

        
    }
};
