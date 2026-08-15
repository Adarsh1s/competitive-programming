class Solution {
public:
    int candy(vector<int>& ratings) {
        int ans = 0;int n = ratings.size();
        vector<int> temp(n,1);
        //left pass
        for(int i = 1;i<n;i++){
            if(ratings[i-1]<ratings[i]) temp[i] = temp[i-1]+1;
            ans += temp[i];
        }
        //right pass
        for(int i = n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                ans -= temp[i];
                temp[i] = max(temp[i+1]+1,temp[i]);
                ans += temp[i];
            }
        }
        return ans+1;
    }
};