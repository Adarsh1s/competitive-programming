/*class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;
        //int p1 = 0,p2 =0;
        int cnt = 0;
        for(int i = 0; i<nums.size()-cnt; i++){
            if(nums[i] == 0){
                
                cnt++;
                for(int j = i; j<nums.size()-1; j++){
                    
                    nums[j] = nums[j+1];
                }
                i--;
            }
        }
        fill(nums.end() - cnt, nums.end(), 0);

    }
};*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;  // Pointer to place the next non-zero element
        for(int i=0;i<nums.size();i++){
            if (nums[i]!=0){
                // Swap current element with the element at index j 
                int temp = nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            
                j++;  // Move j to the next index for placing non-zero
            }
        }
    }
};