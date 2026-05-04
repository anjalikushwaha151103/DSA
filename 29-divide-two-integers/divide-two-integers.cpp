class Solution {
public:
    int divide(int dividend, int divisor) {
        // Edge case: overflow
        if (dividend == INT_MIN && divisor == -1) 
            return INT_MAX;

        if (dividend == 0) return 0;

        // Determine sign
        bool sign = ( (dividend > 0) == (divisor > 0) );

        // Use long long to avoid overflow
        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long ans = 0;

        while (n >= d) {
            long long temp = d, multiple = 1;

            // Safe shifting
            while (n >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            n -= temp;
            ans += multiple;
        }

        // Apply sign
        if (!sign) ans = -ans;

        // Clamp to int range
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return (int)ans;
    }
};