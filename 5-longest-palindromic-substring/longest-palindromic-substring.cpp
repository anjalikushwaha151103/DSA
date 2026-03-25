#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        // Preprocess string: insert '#' between each char and at ends
        string t = "#";
        for (char c : s) {
            t += c;
            t += '#';
        }

        int n = t.size();
        vector<int> p(n, 0); // palindrome radius array
        int maxi = 0;

        // Manacher-like expansion to find palindrome radius at each center
        for (int i = 0; i < n; i++) {
            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
                p[i]++;
            }
            maxi = max(maxi, p[i]);
        }

        // Extract longest palindrome substring from original string
        // Find first center with max radius
        int centerIndex = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] == maxi) {
                centerIndex = i;
                break;
            }
        }

        // Calculate starting index in original string 's'
        int start = (centerIndex - maxi) / 2;
        return s.substr(start, maxi);
    }
};