class Solution {
private:
    int big;
    int maxSubArrayWithSize(vector<int>& nums,int size) {
        int ret = 0;
        if( size == 1 ) {
            return nums[0];
        }
        else {
            ret = maxSubArrayWithSize( nums, size-1 );
        }
        ret += nums[size-1];
        ret = ret > nums[size-1] ? ret : nums[size-1];
        if( ret > big ) {
            big = ret;
        }
        return ret;
    }
public:
    int maxSubArray(vector<int>& nums) {
        big = nums[0];
        maxSubArrayWithSize( nums, nums.size() );
        return big;
    }
};
