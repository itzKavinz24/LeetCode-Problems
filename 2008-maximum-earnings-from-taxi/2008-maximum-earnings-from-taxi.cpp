class Solution {
public:
    int n;

    vector<long long >dp;

    int find(int num , vector<vector<int>> &rides){
        int l=0 , r=n-1;
        long long ans=-1;

        while( l <= r){
            
            long long mid = l + (r-l)/2 ; 
            if( rides[mid][0] >= num){
                r = mid - 1;
                ans= mid;
            }else{
                l =mid + 1;
            }

        }
        return ans;
    }
    long long rec(int i,vector<vector<int>> &rides){
        if(i>=n)return 0;

        if(dp[i]!= -1 ){
            return  dp[i];
        }
        long long  nottake = rec(i+1,rides);
        long long  take = rides[i][1] - rides[i][0] + rides[i][2];    

        // For FInding the llower bound  -> that is th egreatee than or equal to avlue
        int index = find( rides[i][1], rides);
        
        //handling the edge cases wehn binary search return -1
        if(index != -1){
            take += rec(index , rides );
        }

        return dp[i] = max( take, nottake);
    }
    long long maxTaxiEarnings(int k, vector<vector<int>>& rides) {
        n=rides.size();
        dp.resize(n,-1);
        sort(rides.begin(),rides.end());
        
        return rec(0,rides);
    }
};