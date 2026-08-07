class Solution {
public:
    int smallestNumber(int n, int t) {
        int temp = 0;
        for(int i = n;;i++){
            int num = i;
            int ans = 1;
            while(num){
                int d = num%10;
                num = num/10;
                ans = ans*d;
            }
            if(ans%t == 0) {
                temp = i;
                break;
            } 
        }
        return temp;
    }
};