class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        /*int stop = nums.size()-1,temp = 0;
        for(int i = 0;i<k;i++){
            //cout<<1<<endl;
            temp = nums[stop];
            nums.pop_back();
            nums.insert(nums.begin(), temp);
            //cout<<temp<<endl;
            //stop--;
        }*/
        k = k % nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};