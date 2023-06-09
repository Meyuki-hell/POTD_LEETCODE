 int dfs(int headID, vector<int> &informTime, vector<int> ad[]){
        int maxTime = 0;
        for(auto it:ad[headID]){
            maxTime = max(maxTime, dfs(it, informTime, ad));
        }
        return informTime[headID] + maxTime;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
         vector<int> ad[100005];
         for(int i = 0; i < manager.size(); i++){
             if(manager[i] != -1){
                 ad[manager[i]].push_back(i);
             }
         }
         return dfs(headID, informTime, ad);
    }
