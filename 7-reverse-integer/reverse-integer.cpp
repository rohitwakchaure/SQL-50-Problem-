class Solution {
public:
    int reverse(int x) {
        int revno = 0;

        while (x != 0) {
            int digit = x % 10;

            // Check for overflow/underflow before multiplying
            if (revno > INT_MAX / 10 || revno < INT_MIN / 10)
                return 0;

            revno = revno * 10 + digit;
            x = x / 10;
        }

        return revno;
    }
};
