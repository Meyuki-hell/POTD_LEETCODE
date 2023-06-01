class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<pair<int, int>, int> > q;;
        q.push({{0, 0}, 1});

        if(grid[0][0] == 1)
            return -1;
        if(grid[0][0] == 0 && grid.size() == 1 && grid[0].size() == 1)
            return 1;
        vector<vector<bool> > vis(grid.size(), vector<bool>(grid.size(), false));
        vis[0][0] = true;
        while(!q.empty()){
            pair<int, int> p = q.front().first;
            int x = p.first;
            int y = p.second;
            int lengthofPath = q.front().second;
            q.pop();

            vector<pair<int, int> > neigh = {{0, 1},{0, -1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1, 1}};
            for(pair<int, int> it: neigh){
                int x0 = it.first + x;
                int y0 = it.second + y;

                if(x0 >= 0 && y0 >= 0 && x0 < grid.size() &&y0 <grid[0].size() && grid[x0][y0]==0 && !vis[x0][y0]){
                    q.push({{x0, y0}, lengthofPath + 1});
                    vis[x0][y0] = true;

                    if(x0 == grid.size() - 1 && y0 == grid[0].size() - 1){
                        return lengthofPath + 1;
                    }
                }
            }
        }
        return -1;
    }
};
