class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            if(open==0 && s[i]==')') ans++;
            //else if(i==s.size()-1 && s!=0) s += abs(open); 
            else if(s[i]==')') open--;
            else if(s[i]=='(') open++; 
        }
        ans += abs(open);
        return ans;
    }
};