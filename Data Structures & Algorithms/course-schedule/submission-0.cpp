class Solution {
public:
    bool dfs(vector<vector<int>>&graph , vector<int>state , int node){
        if(state[node]==1) return true;
        if(state[node]==2) return false;
        state[node]= 1;
        for(auto neigh:graph[node]){
            if(dfs(graph , state , neigh)) return true;
        }
        state[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>state(numCourses , 0);
        for(auto p:prerequisites){
            graph[p[1]].push_back(p[0]);
        }
        for(int i=0;i<numCourses;i++){
            if(dfs(graph , state , i)){
                return false;
            }

        }
        return true;
        
    }
};
