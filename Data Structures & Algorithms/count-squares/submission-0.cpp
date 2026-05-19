class CountSquares {
public:

    unordered_map<int, unordered_map<int,int>> mp;

    CountSquares() {
        
    }

    void add(vector<int> point) {

        int x = point[0];
        int y = point[1];

        mp[x][y]++;
    }

    int count(vector<int> point) {

        int x = point[0];
        int y = point[1];

        int ans = 0;

        // traverse all possible y values for same x
        for(auto &it : mp[x]) {

            int ny = it.first;

            // same point
            if(ny == y)
                continue;

            int side = ny - y;

            // right square
            ans += mp[x][ny] *
                   mp[x + side][y] *
                   mp[x + side][ny];

            // left square
            ans += mp[x][ny] *
                   mp[x - side][y] *
                   mp[x - side][ny];
        }

        return ans;
    }
};