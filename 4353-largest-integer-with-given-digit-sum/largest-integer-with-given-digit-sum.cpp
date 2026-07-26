class Solution {
public:
    int largestInteger(int n, int s) {
        int ans=0;
        while(n--){
            if(s>=9){
                ans = (ans*10)+9;
                s -= 9;
            }
            else{
                ans = ans = (ans*10)+s;
                s=0;
            }
        }
        return s==0?ans:-1;
    }
};