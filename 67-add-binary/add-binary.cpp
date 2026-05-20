#include <string>
#include <algorithm>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string result = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Loop from right to left until both strings and the carry are processed
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = carry;

            if (i >= 0) {
                sum += a[i] - '0'; // Convert char to int
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0'; // Convert char to int
                j--;
            }

            // Determine the next carry (1 if sum is 2 or 3)
            carry = sum / 2;

            // Append the remainder (0 or 1) to the result string
            result += std::to_string(sum % 2);
        }

        // The result is built backwards, so reverse it before returning
        std::reverse(result.begin(), result.end());
        return result;
    }
};
