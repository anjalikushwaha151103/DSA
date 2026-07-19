class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,vector<char>> mp;
        mp[2]={'a','b','c'};
        mp[3]={'d','e','f'};
        mp[4]={'g','h','i'};
        mp[5]={'j','k','l'};
        mp[6]={'m','n','o'};
        mp[7]={'p','q','r','s'};
        mp[8]={'t','u','v'};
        mp[9]={'w','x','y','z'};

        string s="";
        vector<string> temp;
        temp.push_back(s);
        
        vector<string> ans;

        for(char ch:digits){
            ans.clear();
            int n=ch-'0';
            for(int i=0;i<temp.size();i++){
                string sub=temp[i];
                for(int j=0;j<mp[n].size();j++){
                    sub+=mp[n][j];
                    ans.push_back(sub);
                    sub.pop_back();
                }
            }
            temp.clear();
            temp=ans;
        }

        return ans;
    }
};