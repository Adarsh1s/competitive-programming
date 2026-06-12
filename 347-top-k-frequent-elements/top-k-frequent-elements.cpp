class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int >>> minpq;
        unordered_map<int,int> map;
        for(int x: nums) map[x]++;
        for(auto& pair : map){
            minpq.push({pair.second,pair.first});
            if(minpq.size()>k) minpq.pop();
        }
        while(!minpq.empty()){
            ans.push_back(minpq.top().second);
            minpq.pop();
        }
        return ans;
    }
};