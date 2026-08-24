class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = -1;

        // Step 1: Find the first decreasing element from the right
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;
            }
        }

        // If no pivot exists, the array is in reverse sorted order
        if (pivot != -1) {
            // Step 2: Find the smallest element > nums[pivot] from the right
            for (int j = n - 1; j > pivot; j--) {
                if (nums[j] > nums[pivot]) {
                    // Step 3: Swap pivot and candidate
                    swap(nums[pivot], nums[j]);
                    break;
                }
            }
        }

        // Step 4: Reverse the suffix to get the next smallest arrangement
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};