/*class Solution {
public:
    vector<vector<long long> > dp;
    long long mod = 1e9 + 7;
    long long solve(vector<int> &num){
        if(num.size() <= 1) return 1;

        vector<int>l, r;
        for(int i =1; i < num.size(); i++){
            if(num[i] > num[0]){
                r.push_back(num[i]);

            }
            else{
                l.push_back(num[i]);
            }

        }
        int n = l .size(), m = r.size();
        return solve(l) * solve(r) % mod * dp[m + n][n] % mod;
    }
    int numOfWays(vector<int>& nums) {
        dp = vector<vector<long long>> (nums.size() + 1, vector< long long>(nums.size() + 1, 0));
        for(int i = 1; i < nums.size()+ 1; i++){
            dp[i][0]= 1;
            dp[i][1] = i;
            dp[i][i - 1] = i;
            dp[i][i] = 1;
        }
        for (int i = 2; i < nums.size() + 1; ++i) {
            for (int j = 2; j < nums.size() + 1; ++j) {
                if (i >= j) dp[i][j] = (dp[i - 1][j - 1] % mod + dp[i - 1][j] % mod) % mod;
                else break;
            }
        }
        return solve(nums) - 1;
    }

};*/


struct TreeNod {
      int val;
      TreeNod *left;
      TreeNod *right;
      TreeNod() : val(0), left(nullptr), right(nullptr) {}
      TreeNod(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNod(int x, TreeNod *left, TreeNod *right) : val(x), left(left), right(right) {}
 };
class Solution {
private:
    vector<int> facts;
    int d;
public:
    void TreeNode1(int &num, TreeNod* &root)
    {
        if(!root) root = new TreeNod(num);
        else if(root -> val < num) TreeNode1(num, root -> right);
        else TreeNode1(num, root -> left);
    }
    void helper1()
    {
        int f = 1;
        facts.push_back(f);
        for(int i = 1; i < 1001; i++)
        {
            f = ((long long) f * i)%d;
            facts.push_back(f);
        }
    }
    int fast_exp(int base, int exp)
    {
        int ans = 1;
        while(exp)
        {
            if(exp%2)
            {
                ans = ((long long) ans * base)%d;
            }
            base = ((long long)base*base)%d;
            exp /= 2;
        }
        return ans;
    }
    pair<int, int> solve(TreeNod *&root)
    {
        if(!root) return {1,0};
        pair<int, int> k1 = solve(root -> left);
        pair<int, int> k2 = solve(root -> right);
        int ans = ((long long) k1.first * k2.first)%d;
        ans = ((long long) ans * facts[k1.second + k2.second])%d;
        int temp = ((long long) facts[k1.second]*facts[k2.second])%d;
        temp = fast_exp(temp, d - 2);
        ans = ((long long) ans * temp)%d;
        return {ans, k1.second + k2.second + 1};
    }
    int numOfWays(vector<int>& nums) {
        d = 1e9 + 7;
        TreeNod *head = nullptr;
        for(auto &k: nums) TreeNode1(k, head);
        helper1();
        return (solve(head)).first - 1;
    }
};
