class Solution {
public:

    bool check(vector<int>a, vector<int>b){
        long long radius = pow(a[2],2);
        long x = pow(a[0] - b[0], 2);
        long y = pow(a[1] - b[1], 2);

        if(x + y <= radius){
            return true;
        }
        return false;
    }

    void dfs(vector<int> *graph, int vertex, vector<bool>&visited, int &count){
        visited[vertex] = true;
        count++;
        for(int it: graph[vertex]){
            if(!visited[it]){
                dfs(graph, it, visited, count);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int v = bombs.size();
        vector<int> graph[v];
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(i  != j){
                    if(check(bombs[i], bombs[j])){
                      graph[i].push_back(j);
                    }
                }
            }
        }

        vector<bool> visited(v, false);

        int maxBomb = INT_MIN;
        for(int i = 0; i < v; i++){
            int count = 0;
            dfs(graph, i, visited, count);

            maxBomb = max(maxBomb, count);
            for(int j = 0; j < v; j++){
                visited[j] = false;
            }
        } 
        return maxBomb;
    }
};
