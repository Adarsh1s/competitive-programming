class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       priority_queue<pair<int, pair<int, int>>> pq;
       vector<vector<int>> ans;int c =0;
       for(int i=0;i<nums1.size();i++){
        for(int j=0;j<nums2.size();j++){
            int sum = nums1[i] + nums2[j];
                

            if (pq.size() == k && sum >= pq.top().first) {
                break; 
            }
            
            pq.push({sum, {nums1[i], nums2[j]}});
            
            if (pq.size() > k) {
                pq.pop();
            }
        }
       }
        while(k--) {
            auto curr=pq.top().second;
            ans.push_back({curr.first,curr.second});
            pq.pop();
        }
        return ans; 
    }
};