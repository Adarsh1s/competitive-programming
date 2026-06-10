class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ans;
        vector<vector<string>> res;
        for(string s : strs){
            string temp = s;
            sort(temp.begin(),temp.end());
            ans[temp].push_back(s);
        }
        for(auto x : ans){
            res.push_back(x.second);
        }
        return res;
    }
};