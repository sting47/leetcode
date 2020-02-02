class Solution {
    private:
    long long int reverseInt(int x) {
        long long int rev = 0;
        while (x != 0) {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }
    public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        if ((long long int)x == reverseInt(x)) {
            return true;
        }
        else {
            return false;
        }
    }
};
