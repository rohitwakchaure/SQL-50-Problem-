class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        // Calculate the sign of the result
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        
        // Work with absolute values
        long long a = labs(dividend);
        long long b = labs(divisor);
        
        long long result = 0;
        
        // Iterate from the highest bit to the lowest bit
        for (int i = 31; i >= 0; i--) {
            if ((a >> i) >= b) {
                result += 1LL << i;
                a -= b << i;
            }
        }
        
        result = sign * result;
        // Check for overflow again after calculation
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        return result;
    }
};
