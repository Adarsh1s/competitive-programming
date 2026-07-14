class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> freq,tails;
        for(int i:nums){
            freq[i]++;
        }
        for(int num:nums){
            if(freq[num]==0) continue;
            if(tails[num]>0){
                tails[num]--;
                tails[num+1]++;
            }
            else if(freq[num+1]>0 && freq[num+2]>0){
                freq[num+1]--;
                freq[num+2]--;
                tails[num+3]++;
            }
            else return false;
            freq[num]--;
        }
        return true;
    }
};