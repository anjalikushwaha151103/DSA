class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int cnt=0;
        int mini=0;
        int maxi=0;
        
        for(char ch:s){
            if(ch=='('){
                mini++;
                maxi++;
            }else if(ch==')'){
                mini--;
                maxi--;
            }else if(ch=='*'){
                mini--;
                maxi++; 
            }
            if(mini<0) mini=0;
            if(maxi<0) return false;
        }
        if(mini==0) return true;
        return false;
        
    }
};