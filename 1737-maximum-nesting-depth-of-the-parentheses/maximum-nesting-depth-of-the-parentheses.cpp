class Solution {
public:
    int maxDepth(string s) {
        stack<char> stk;
        int max1=0, ans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') {
                max1++;
                stk.push('(');
            }
            else if(s[i]==')'){
                max1--;
                stk.pop();
            }
            else continue;
            ans = max(ans,max1);
        }
        return ans;
    }
};