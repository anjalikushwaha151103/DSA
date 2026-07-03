class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string ans="";
        for(int i=0;i<strs[0].size();i++){
            char match=strs[0][i];
            for(int j=1;j<n;j++){
                if(i==strs[j].size() || strs[j][i]!=match){
                    return ans;
                }
            }
            ans+=match;
        }
        return ans;
    }
};