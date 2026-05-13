class Solution {
public:
    int numberOfSubstrings(string s) {

        unordered_map<int,int> mp;
        int n= s.size();
        int l=0;
        int cnt=0;
        for(int r=0;r<n;r++){
            mp[s[r]]++;

            while(mp.size() == 3) {

                cnt += (n - r);

                mp[s[l]]--;

                if(mp[s[l]] == 0) {
                    mp.erase(s[l]);
                }

                l++;
            }
        }
        return cnt;
    }
};