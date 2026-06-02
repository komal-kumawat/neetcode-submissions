class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>>adj(26);
        vector<int>indegree(26,0);
        vector<bool>present(26 , false);
        for(auto word:words){
            for(auto ch:word){
                present[ch-'a'] = true;
            }
        }
        for(int i=0;i<words.size()-1;i++){
            string w1 = words[i] , w2 = words[i+1];
            int j = 0 , l1 = w1.size() , l2 = w2.size() , minLen = min(l1,l2);
            while(j<minLen && w1[j]==w2[j]) j++;
            if(j==minLen && l1>l2) return "";
            if(j<minLen) {
                int u = w1[j]-'a' , v = w2[j]-'a';
                adj[u].push_back(v);
                indegree[v]++;
            }

        }
        queue<int>q;
        for(int i=0;i<26;i++){
            if(present[i]&& indegree[i]==0) q.push(i);
        }
        string res = "";
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res = res+char(node+'a');
            for(auto neighbour:adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }
        for(int i=0;i<26;i++){
            if(present[i] && res.find(i+'a')==string::npos) return "";
        }
        return res;
    }
};
