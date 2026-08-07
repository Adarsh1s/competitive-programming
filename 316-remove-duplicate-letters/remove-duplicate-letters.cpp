class Solution {
public:
    string removeDuplicateLetters(string s) {
        int last[26] = {};
        for(int i = 0;i<s.size();i++){
            last[s[i]-'a'] = i;
        }
        bool instack[26] = {};
        string stack;
        for(int i = 0;i<s.size();i++){
            char ch = s[i];
            if(instack[ch-'a']) continue;
            
            while(!stack.empty() && stack.back() > ch && last[stack.back()-'a']>i){
                instack[stack.back()-'a'] = false;
                stack.pop_back();
            }
            stack.push_back(ch);
            instack[ch-'a'] = true;
        }
        
        return stack;
    }
};