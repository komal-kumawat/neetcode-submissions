class Solution {
public:
    vector<vector<int>>distArr = {{-1 , 0} , {1,0} , {0 , 1} , {0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i , j});
                }
            }
        }
        int dist = 0;
        while(!q.empty()){
            dist++;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto [x , y] = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int dx = x+distArr[j][0];
                    int dy = y+distArr[j][1];
                    if(dx<0 || dy<0 || dx>=m || dy>=n || grid[dx][dy]==-1 || grid[dx][dy]<dist){
                        continue;
                    }
                    grid[dx][dy] = dist;
                    q.push({dx , dy});
                }
            }

        }

        
    }
};
