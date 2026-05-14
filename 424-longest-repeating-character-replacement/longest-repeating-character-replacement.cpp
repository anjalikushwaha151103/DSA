class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int l=0;
        int r=0;
        int max_len=0;
        int max_f=0;
        int arr[26]={0};
        int chng=0;
        while(r<n){
            arr[s[r]-'A']++;
            max_f=max(max_f,arr[s[r]-'A']);
            chng=(r-l+1)-max_f;
            while(chng>k){
                arr[s[l]-'A']--;
                l++;
                chng=(r-l+1)-max_f;
            }
            max_len=max(max_len,(r-l+1));
            r++;
        }
        return max_len;
    }
};