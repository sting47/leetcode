// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int ret = 0;
        long long unsigned int high = n;
        long long unsigned int low = 1;
        long long unsigned int myG = n;
        do {
            ret = guess( myG );
            if( ret == -1 ) {
                high = myG;
                myG = (low+high)/2;
            }
            else if( ret == 1 ) {
                low = myG;
                myG = (low+high)/2;
            }
        } while( ret != 0 );
        return myG;
    }
};
