class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n= fruits.size();
        int l=0;
        int max_len=0;
        for(int r=0;r<n;r++){
            mp[fruits[r]]++;

            while(mp.size() > 2) {
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0)
                    mp.erase(fruits[l]);
                l++;
            }

            max_len=max(max_len,r-l+1);

        }
        return max_len;
    }
};