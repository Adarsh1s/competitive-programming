class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<array<int, 3>> jobs(n);
        for(int i = 0;i<n;i++){
            jobs[i]={startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(),jobs.end());
        
        vector<int> memo(n,-1);
        vector<int> starts(n);
        for(int i = 0;i<n;i++) starts[i] = jobs[i][0];

        return helper(jobs,memo,starts,n,0);


    }
private:
    int helper( vector<array<int, 3>>& jobs,vector<int>& memo,vector<int>& starts,int& n,int i) {
        if(i>=n) return 0;
        if(memo[i] != -1) return memo[i];

        //skip
        int skip = helper(jobs,memo,starts,n,i+1);
        //dont skip
        int next = lower_bound(starts.begin()+i+1,starts.end(),jobs[i][1])-starts.begin();
        int take = jobs[i][2] + helper(jobs,memo,starts,n,next);

        return memo[i]=max(skip,take);

    }
};