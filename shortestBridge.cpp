class Solution {
public:

    int m, n;
    vector<vector<int>> d ={{-1,0}, {0,-1}, {0, 1}, {1, 0}};

    bool isSafe(int i, int j){
        return (i < m && i >= 0 && j < n && j >= 0);
    }

    void dfs(vector<vector<int>> &grid, int i, int j, set<pair<int, int>>& visCell){
        if(!isSafe(i, j) || grid[i][j] == 0 || visCell.find({i, j}) != visCell.end()){
            return;
        }
        visCell.insert({i, j});

        for(auto &dir : d){
            int i0 = i + dir[0];
            int j0 = j + dir[1];

            dfs(grid, i0, j0, visCell);
        }
    }

    int bfs(vector<vector<int>>& grid, set<pair<int, int>>& visCell){
        queue<pair<int, int>> q;
        for(auto &it : visCell){
            q.push({it});
        }

        int lev = 0;
        while(!q.empty()){
            int l = q.size();
            while(l--){
                pair<int, int> p = q.front();
                q.pop();
                for(auto &dir : d){
                    int i0 = p.first + dir[0];
                    int j0 = p.second + dir[1];

                    if(isSafe(i0, j0) && visCell.find({i0, j0}) == visCell.end()){
                        if(grid[i0][j0] == 1)
                            return lev;
                    
                        visCell.insert({i0, j0});
                        q.push({i0, j0});
                    }
                }
            }
            lev++;

        }
        return lev;
    }


    int shortestBridge(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        set<pair<int, int>> visCell;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    dfs(grid, i, j, visCell);
                    return bfs(grid, visCell);
                }
            }
        }
        return -1;        
    }
};
