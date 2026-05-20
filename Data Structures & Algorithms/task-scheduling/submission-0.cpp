class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int>hash;
        for(int task:tasks){
            hash[task]++;
        }
        priority_queue<int>pq;
        for(auto&[task , freq]:hash){
            pq.push(freq);
        }
        queue<pair<int , int>>q;
        int time = 0;
        while(!q.empty()|| !pq.empty()){
            time++;
            if(!pq.empty()){
                int cnt = pq.top();
                cnt--;
                pq.pop();
                if(cnt>0){
                    q.push({cnt , time+n});
                }
            }
            if(!q.empty() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }

        }
        return time;
        
    }
};
