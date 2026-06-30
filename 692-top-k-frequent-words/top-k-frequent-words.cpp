class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        map<string,int> map;
        for(string a:words) map[a]++;
        vector<vector<string>> freq(words.size()+1);
        for(auto& x:map) freq[x.second].push_back(x.first);
        for(int i = words.size();i>0;i--){
            for(string c : freq[i]) {
                ans.push_back(c);
                if(ans.size() == k) break;
            }
            if(ans.size() == k) break;
        }
        return ans;
    }
};