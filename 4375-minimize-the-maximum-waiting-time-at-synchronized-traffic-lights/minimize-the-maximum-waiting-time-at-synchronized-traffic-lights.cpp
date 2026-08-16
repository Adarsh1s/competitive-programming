class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int ans=0;
        for(int i = 0;i<arrivalTime.size();i++){
            arrivalTime[i] = arrivalTime[i]%period;
        }
        int max1 = 0;
        for(int i = 0;i<lights.size();i++){
            max1=max(max1,lights[i]);
        }
        for(int i = 0;i<arrivalTime.size();i++){
            if(arrivalTime[i]<max1) continue;
            ans = max(ans,period-arrivalTime[i]);
        }
        return ans;
    }
};