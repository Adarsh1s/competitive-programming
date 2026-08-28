class Solution {
public:
    const int m = 1e9+7;
    int helper(long long base,long long power){
        long long result = 1;
        base %= m;

        while(power>0){
            if(power%2==1) result=(result*base)%m;
            base=(base*base)%m;
            power /= 2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;

        long long evenways = helper(5,even);
        long long oddways = helper(4,odd);

        return (evenways * oddways) % m;
    }
};