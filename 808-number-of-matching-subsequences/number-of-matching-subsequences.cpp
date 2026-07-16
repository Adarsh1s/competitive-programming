class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        vector<vector<int>> charpos(26);
        for(int i = 0;i<s.size();i++) charpos[s[i]-'a'].push_back(i);
        for(const string& word:words){
            if(match(word,charpos)) ans++;
        }
        return ans;
    }
private:
    bool match(const string& word,vector<vector<int>>& charpos){
        int pre=-1;
        for(char ch:word){
            const vector<int>& pos = charpos[ch-'a'];
            auto it=upper_bound(pos.begin(),pos.end(),pre);
            if(it==pos.end()) return false;
            pre=*it;
        }
        return true;
        
    }
};