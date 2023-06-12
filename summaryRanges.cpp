class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> v;

       
        //int e = nums[0];
        int n = nums.size();
        if(n == 0)
            return v;
        
        int s = nums[0];

        for(int i = 0; i < n; i++){
            if(i == n - 1 || nums[i] + 1 != nums[i+1]){
                if(nums[i] != s){
                    v.push_back(to_string(s) + "->" + to_string(nums[i]));
                }
           
                else{
                    v.push_back(to_string(s));

                }
                if(i != nums.size() - 1){
                    s = nums[i+1];
                }
            }
        }
        return v;
    }
};
