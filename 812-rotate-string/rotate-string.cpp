class Solution {
public:
    bool rotateString(string s, string goal) {
        string doubled = s + s;

        return doubled.find(goal) != string::npos;
    }
};