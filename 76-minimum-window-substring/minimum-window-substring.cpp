class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int required = t.size();

        if (required > n) return "";

        int freq[256] = {0};

        for (char c : t)
            freq[(unsigned char)c]++;

        int l = 0;
        int matched = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int r = 0; r < n; r++) {

            if (freq[(unsigned char)s[r]] > 0)
                matched++;

            freq[(unsigned char)s[r]]--;

            while (matched == required) {

                int windowLen = r - l + 1;

                if (windowLen < minLen) {
                    minLen = windowLen;
                    start = l;
                }

                freq[(unsigned char)s[l]]++;

                if (freq[(unsigned char)s[l]] > 0)
                    matched--;

                l++;
            }
        }

        return minLen == INT_MAX
               ? ""
               : s.substr(start, minLen);
    }
};