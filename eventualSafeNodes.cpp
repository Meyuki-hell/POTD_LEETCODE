class Solution {
    public:
        bool solve(int node,vector<vector<int>>& graph,vector<int> &vis,vector<int> &path,vector<int> &check){
            vis[node] = true;
            path[node] = true;
            for(auto child: graph[node]){
                if(vis[child]==0 ){
    
                
                    if(solve(child,graph,vis,path,check)){
                        return true;
                    }
                }
                else if(path[child]==1){
                    return true;
                }
            }
            check[node] = 1;
            path[node] = false;
            
            return false;
            
        }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V,0);
        vector<int> path(V,0);
        vector<int> check(V,0);
        vector<int> ans;
        for(int i= 0;i<V;i++){
            if(vis[i]==0){
                solve(i,graph,vis,path,check);
            }
        }
        for(int i= 0;i<V;i++){
            if(check[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

/*class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        
        vector<vector<int>> rev_graph(n);
        vector<int> out_deg(n,0);
        for(int i=0;i<n;i++){
            out_deg[i] += graph[i].size();
            for(int v : graph[i]) rev_graph[v].push_back(i);
        }
        
        queue<int> q;
        for(int i=0;i<n;i++) if(out_deg[i]==0) q.push(i);
        
        vector<bool> is_safe(n,false);
        while(q.size()>0){
            int node = q.front();
            q.pop();
            
            is_safe[node]=true; 
            for(int child : rev_graph[node]){
                if(--out_deg[child] == 0) q.push(child);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++) if(is_safe[i]) ans.push_back(i);

        return ans;
    }
};*/
