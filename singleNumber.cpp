class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int it : nums){
            ones = (ones ^ it) & (~twos);
            twos = (twos ^ it) & (~ones); 
        }
        return ones;
    }
};
