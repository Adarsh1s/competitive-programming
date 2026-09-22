class Solution {
public:
    void helper(vector<vector<int>>& pairs,int n,vector<int>& dp,int id){
        for(int j = 0;j<id;j++){
            if(pairs[j][1]<pairs[id][0]){
                dp[id] = max(dp[id],dp[j]+1);
            }
        }
        
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<int> dp(n,1);

        sort(pairs.begin(),pairs.end(),[](const vector<int>& a,const vector<int>& b){
            return a[0]<b[0];
        });
        //for greddy approach - n(logn)
        //sort(pairs.begin(),pairs.end(),[](const vector<int>& a,const vector<int>& b){
        //    return a[1]<b[1];
        //});

        for(int i = 0;i<n;i++) helper(pairs,n-1,dp,i);
        int ans = INT_MIN;
        for(int i = 0;i<n;i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};