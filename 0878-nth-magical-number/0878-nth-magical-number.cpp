class Solution {
public:
    int gd(int a,int b){
        if(b>a){
            swap(a,b);
        }
        if(b==0)return a;
        return gd(b,a%b);
    }
    int nthMagicalNumber(int n, int a, int b) {
        long long l =0 ;
        long long r = 1LL * n * min(a, b);
        long long gc =gd(a,b); 
        long long lcm = (1LL * a * b) / gc;
        long long ans =0;
        while(l<=r){
            long long mid = l + (r -l)/2;
            long long count = (mid/a) + (mid/b) - (mid/lcm);
            if(count>=n){
                ans = mid;
                r =mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans%1000000007;
    }
};