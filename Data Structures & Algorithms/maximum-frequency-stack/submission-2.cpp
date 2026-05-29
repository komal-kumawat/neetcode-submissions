class FreqStack {
public:
    unordered_map<int , int>freq;
    unordered_map<int , stack<int>>group;
    int maxfreq;
    FreqStack() {
        maxfreq = 0;
        
    }
    
    void push(int val) {
        freq[val]++;
        int f = freq[val];
        maxfreq = max(f , maxfreq);
        group[f].push(val);

        
    }
    
    int pop() {
        int ans = group[maxfreq].top();
        group[maxfreq].pop();
        freq[ans]--;
        if(group[maxfreq].empty()){
            maxfreq--;
        }
        return ans;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */