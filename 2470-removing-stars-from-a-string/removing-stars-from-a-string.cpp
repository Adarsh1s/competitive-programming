class Solution {
public:
    string removeStars(string s) {
       stack<char> stac;
       for(int i = 0;i<s.size();i++){
        if(stac.empty() && s[i] == '*') continue;
        else if(s[i] == '*') stac.pop();
        else stac.push(s[i]);
       } 
       string ans = "";
       while(!stac.empty()){
        ans.push_back(stac.top());
        stac.pop();
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};