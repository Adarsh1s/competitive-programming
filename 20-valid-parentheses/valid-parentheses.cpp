class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        for (char s1 : s) {
            if(s1 == '(') ans.push(')');
            else if(s1 == '{') ans.push('}');
            else if(s1 == '[') ans.push(']');
            else{
                if(ans.empty() || s1 != ans.top()) return false; 
                ans.pop();
            }
        } 
        return ans.empty();
    }
};