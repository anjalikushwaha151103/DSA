class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        int ans = -1;

        int i = 0;
        while(i < n && ans == -1){
            if(haystack[i] == needle[0]){
                ans = i;
                int k = i;

                for(int j = 0; j < m; j++){
                    if(k >= n || haystack[k] != needle[j]){
                        ans = -1;
                        break;
                    }
                    k++;
                }
            }
            i++;
        }
        return ans;
    }
};