class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(int num:stones){
            q.push(num);
        }
        while(q.size()>1){
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            if(abs(x-y)>0){
                q.push(abs(x-y));
            }
        }
        if(q.size()!=0) return q.top();
        return 0;
        
    }
};
