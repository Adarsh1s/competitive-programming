class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int ans = 0;
        for(int i = 0;i<requests.size();i++){
            if(i==0) ans += requests[i];
            else
            ans += abs(requests[i]-requests[i-1]);
        }
        return ans;
    }
};