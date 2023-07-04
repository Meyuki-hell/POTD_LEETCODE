class Solution {
public:
    int solve(vector<vector<int>> &requests, vector<int> &help, int i){
        if(i == requests.size()) {
            for(int it : help){
                if(it != 0){
                    return INT_MIN;
                }
            }return 0;
        }

        help[requests[i][0]]++;
        help[requests[i][1]]--;

        int take = 1 + solve(requests, help, i+1);

        help[requests[i][0]]--;
        help[requests[i][1]]++;

        int notTake = solve(requests, help, i+1);

        return max(take, notTake);

    }
    
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int>help(n, 0);
        return solve(requests, help, 0);
    }
};
