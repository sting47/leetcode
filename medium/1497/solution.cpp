class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int i = 0;
        // init modCnt with k size
        for( i = 0; i < k; i++ ) {
            modCnt.push_back(0);
        }
        // fill modCnt
        for( i = 0; i < arr.size(); i++ ) {
            if( arr[i] < 0 )
                arr[i] = arr[i] - (arr[i] / k - 1) * k;
            modCnt[arr[i] % k]++;
        }
        // check 0 cnt is even? continue : false
        if( modCnt[0] % 2 != 0 )
            return false;
        // if k is odd, check mid is even? continue; false
        if( k % 2 == 0 )
            if( modCnt[k/2] % 2 != 0 )
                return false;
        // check other pair sum
        for( i = 1; i <= (k-1)/2; i++ ) {
            if( modCnt[i] != modCnt[k-i] )
                return false;
        }
        return true;
    }
private:
    vector<int> modCnt;
};
