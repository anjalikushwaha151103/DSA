class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int l=0;
        int r=0;
        int max_len=0;
        int max_f=0;
        unordered_map<char,int> mp;
        int chng=0;

        while(r<n){
            
            mp[s[r]]++;
            max_f=max(max_f,mp[s[r]]);
            chng=(r-l+1)-max_f;

            while(chng>k){
                mp[s[l]]--;
                l++;
                chng=(r-l+1)-max_f;
            }

            max_len=max(max_len,(r-l+1));
            r++;
        }
        return max_len;
    }
};