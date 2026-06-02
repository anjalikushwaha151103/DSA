class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> rev;

        vector<string> words;
        string word = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += s[i];
            }
        }

        if (!word.empty())
            words.push_back(word);

        if (pattern.size() != words.size())
            return false;

        for (int i = 0; i < pattern.size(); i++) {

            if (mp.find(pattern[i]) != mp.end()) {
                if (mp[pattern[i]] != words[i])
                    return false;
            } else {
                mp[pattern[i]] = words[i];
            }

            if (rev.find(words[i]) != rev.end()) {
                if (rev[words[i]] != pattern[i])
                    return false;
            } else {
                rev[words[i]] = pattern[i];
            }
        }

        return true;
    }
};