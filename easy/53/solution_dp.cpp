class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp[nums.size()];
        int i = 0;
        int big = nums[0];
        dp[0] = nums[0];
        // using DP to construct the table
        for( i=1; i<nums.size(); i++ ) {
            if( (nums[i] + dp[i-1]) > nums[i] ) {
                dp[i] = nums[i] + dp[i-1];
            }
            else {
                dp[i] = nums[i];
            }
        }
        
        // go through the table to get largest sum
        for( i=1; i<nums.size(); i++ ) {
            if( dp[i] > big ) {
                big = dp[i];
            }
        }
        return big;
    }
};
