class Solution {
public:
    int climbStairs(int n) {
        vector<int> v(n+1,0);
        return helper(n,v);
    }
private:
    int helper(int n,vector<int>& v){
        if(n==1) return 1;
        if(n==2) return 2;
        if(v[n] != 0) return v[n];
        v[n] = helper(n-1,v) + helper(n-2,v);
        return v[n];
    }
};