class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0;
        int r=0;
        unordered_map <char,int> mp;
        int max_len=0;

        while(r<n){
            if(mp.find(s[r])==mp.end()){
                mp[s[r]]=r;
                
            }else{
                l = max(l, mp[s[r]] + 1);
                mp[s[r]]=r;
            }
            max_len=max(max_len,(r-l+1));
            r++;
        }

        return max_len;
        
    }
};