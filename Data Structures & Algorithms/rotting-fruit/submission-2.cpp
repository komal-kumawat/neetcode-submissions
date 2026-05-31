class Solution {
public:
    vector<vector<int>>distArr = {{-1 , 0} , {1,0} , {0 , 1} , {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        queue<pair<int,int>>q;
        int fresh = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i , j});
                }else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int time = 0;
        while(!q.empty() && fresh>0){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto [x , y] = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int dx = x+distArr[j][0];
                    int dy = y+distArr[j][1];
                    if(dx<0 || dy<0 || dx>=m || dy>=n || grid[dx][dy]==0||grid[dx][dy]==2){
                        continue;
                    }
                    grid[dx][dy] = 2;
                    fresh--;
                    q.push({dx , dy});
                }
            }
            time++;


        }
        
        
        return fresh==0?time:-1;
        
    }
};
