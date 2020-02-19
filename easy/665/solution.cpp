class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int i = 0;
        bool bIsTheOne = false;
        for( i=0; i<nums.size()-1; i++ ) {
            if( nums[i] > nums[i+1] ) {
                if( bIsTheOne == false ) {
                    if( i == 0 || i == nums.size()-2 ) {
                        bIsTheOne = true;
                        continue;
                    }
                    else if( nums[i-1] <= nums[i+1] ) {
                        bIsTheOne = true;
                        continue;
                    }
                    else if( nums[i] <= nums[i+2] ) {
                        bIsTheOne = true;
                        continue;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
