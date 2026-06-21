class Solution {
public:
    int maxArea(vector<int>& height) {
        int f = 0, last = height.size()-1;
        int result = 0;
        while(f<last){
            int temp = min(height[f],height[last]);
            result = max(result,((last-f)*temp));
            if(height[f]<height[last]) f++;
            else last--;
        }
        return result;
    }
};