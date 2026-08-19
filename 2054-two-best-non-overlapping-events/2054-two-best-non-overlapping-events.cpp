class Solution {
public:
    int n;
    vector<vector<int>>dp;
    int find (int i , vector<vector<int>> &events ){

        int l = 0, r = n - 1 ;
        int ans = -1;
        while( l <= r){
            int mid = l+ (r -l)/2;

            if(events[mid][0] > i){

                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
    int rec(int i,int k ,vector<vector<int>> &events){
        if(i >= n || k <= 0) return 0;

        if(dp[i][k] != -1)return dp[i][k];
        int nottake = rec( i + 1 , k , events );

        int take = events[i][2];
        int index = find(events[i][1] , events);

        if(index != -1){
            take += rec( index , k - 1 , events );
        }else{
            take += 0;
        }

        return dp[i][k] =  max( take , nottake );

    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();

        dp.resize(n,vector<int>(3,-1));

        sort(events.begin(),events.end());
        return rec( 0 , 2 , events);
    }
};