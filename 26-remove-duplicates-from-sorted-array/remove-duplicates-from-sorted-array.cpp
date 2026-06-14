/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 1;
        for(int i = 1;i<n;i++){
            if(nums[i] != nums[j-1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int temp=0;
        for(int i =1;i<nums.size();i++){
            if(nums[temp] == nums[i]) continue;
            else{
                nums[temp+1]=nums[i];
                temp++;
            }
        }
        return temp+1;
    }
};