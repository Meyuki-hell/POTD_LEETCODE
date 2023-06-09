void dfs(int node, vector<int> &visited, vector<int> adj[]){
        if(visited[node]) return;
        visited[node] = 1;
        for(auto val : adj[node]){
            dfs(val, visited, adj);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<int> visited(n+1, 0);

        vector<int> adj[n+1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] && i != j){
                    adj[i+1].push_back(j + 1);
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(!visited[i]){
                dfs(i, visited, adj);
                count++;
            }
        }
        return count;
    }
