class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int element,max=0;
        for(int x: nums){
            map[x]++;
            if(max<map[x]){
                max=map[x];
                element = x;
            }
        }
        return element; 
    }
};