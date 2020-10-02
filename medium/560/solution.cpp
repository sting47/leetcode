class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int i = 0;
        cnt = 0;
        sum = 0;
        sumMap.insert( pair<int,int>(0, 1) );
        unordered_map<int, int>::iterator it;
        for( i = 0; i < nums.size(); i++ ) {
            sum += nums[i];
            
            // find sum - k and update cnt
            it = sumMap.find(sum - k);
            if( it != sumMap.end() ) {
                cnt += sumMap[sum - k];
            }
            
            // update sumMap
            it = sumMap.find(sum);
            if( it != sumMap.end() ) {
                sumMap[sum]++;
            }
            else {
                sumMap.insert( pair<int,int>(sum, 1) );
            }
        }
        
        return cnt;
    }
private:
    // running sum array of nums
    int sum;
    unordered_map<int, int> sumMap;
    int cnt;
};
