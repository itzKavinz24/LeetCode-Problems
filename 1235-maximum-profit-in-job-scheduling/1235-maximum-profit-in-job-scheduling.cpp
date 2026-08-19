class Solution {
public:
    vector<int>dp;
    vector<vector<int>>arr;
    int n;

    int find(int num,vector<vector<int>> &arr){
        int l=0,r=n-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(arr[mid][0]>=num){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    int rec(int i){
        if(i>=n)return 0;
        if(dp[i] !=-1)return dp[i];
        int ntake = rec(i+1);
        int index = find(arr[i][1],arr);
        int take = arr[i][2];
        if(index!=-1)
        take+=rec(index);
        return dp[i] = max(take,ntake);

    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        n=startTime.size();
        arr.resize(n);
        dp.resize(n,-1);
        for(int i=0;i<n ; i++){
            arr[i]={startTime[i],endTime[i],profit[i]};
        }
        sort(arr.begin(),arr.end());
        return rec(0);

    }
};