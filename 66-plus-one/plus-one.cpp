class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int num = 0;
        vector<int> ans;
        if(digits[digits.size()-1]+1>9){
            num = digits[digits.size()-1]+1;
            ans.insert(ans.begin(),num%10);
            num = num/10;
            for(int i = digits.size()-2;i>=0;i--){
                if(num>0){
                    if(digits[i]+num>9){
                        num = digits[i]+num;
                        ans.insert(ans.begin(),num%10);
                        num = num/10;
                    }
                    else{
                        ans.insert(ans.begin(),digits[i]+num);
                        num = num/10;
                    }
                }
                else ans.insert(ans.begin(),digits[i]);
            }
        }
        else{
            ans.insert(ans.begin(),digits[digits.size()-1]+1);
            for(int i = digits.size()-2;i>=0;i--)
                ans.insert(ans.begin(),digits[i]);
        }
        if(num>0) ans.insert(ans.begin(),num);
        return ans;
    }
};