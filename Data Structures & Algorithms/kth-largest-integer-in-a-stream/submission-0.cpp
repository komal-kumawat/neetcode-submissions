class KthLargest {
public:
    priority_queue<int , vector<int>,greater<int>>q;
    int sz = 0;
    KthLargest(int k, vector<int>& nums) {
        sz = k;
        for(int num:nums){
            q.push(num);
            // if(q.size()>k){
            //     q.pop();
            // }
        }
    }
    
    int add(int val) {
        q.push(val);
        while(q.size()>sz){
            q.pop();
        }
        return q.top();
        
    }
};
