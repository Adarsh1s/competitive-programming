class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low<high){
            int mid = low + (high-low)/2;
            if(canship(weights,days,mid)){
                high = mid;
            }
            else low = mid + 1;
        }
        return low;
    }
    bool canship(vector<int>& weights, int& days, int& capacity){
        int days_cnt = 1,curr_load = 0;
        for(int x : weights){
            if(curr_load+x>capacity){
                days_cnt++;
                curr_load = 0;
            }
            curr_load += x;
            if(days_cnt>days) return false; 
        }
        return true;
    }
};