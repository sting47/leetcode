class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int i = 1;
        // init rnums[0]
        rnums.push_back( nums[0] );
        for( ; i < nums.size(); i++ ) {
            rnums.push_back( rnums[i-1] + nums[i] );
        }
        return rnums;
    }
private:
    vector<int> rnums;
};
