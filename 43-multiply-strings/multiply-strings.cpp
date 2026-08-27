class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        int n1 = num1.size(), n2 = num2.size();
        vector<int> ans(n1+n2,0);
        for(int i = n1-1;i>=0;i--){
            for(int j = n2-1;j>=0;j--){
                int mul = (num1[i]-'0') * (num2[j]-'0');
                int p1 = i+j,p2 = i+j+1;
                int sum = mul+ans[p2];

                ans[p2]=sum%10;
                ans[p1]+=sum/10;
            }
        }
        string result;
        for(int digit:ans){
            if(!(result.empty() && digit == 0)) result += to_string(digit);
        }
        return result;
    }
};