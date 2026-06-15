class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pointer = 0;
        if(s.empty()) return true;
        for(int i = 0;i<t.size();i++){
            if(pointer == s.size()) return true;
            else if(s[pointer]==t[i]) pointer++;
        }
        return pointer == s.size();
    }
};