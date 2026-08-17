class Solution {
public:
    vector<int>prefix;
    vector<vector<int>>dp;
    int n;
    int rec(int l,int r,vector<int>& stoneValue){
        if(l>r)return 0;
        if(l==r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=0;
        for(int i=l;i<r;i++){
            int leftsum=prefix[i]-(l==0?0:prefix[l-1]);
            int rightsum=prefix[r]-prefix[i];
            if(leftsum<rightsum){
                ans=max(ans,leftsum+rec(l,i,stoneValue));
            }
            else if(leftsum>rightsum){
                ans=max(ans,rightsum+rec(i+1,r,stoneValue));
            }
            else{
                ans=max({ans,leftsum+rec(l,i,stoneValue),rightsum+rec(i+1,r,stoneValue)});
            }
        }
        return dp[l][r]=ans;

        
    }
    int stoneGameV(vector<int>& stoneValue) {
        n=stoneValue.size();
        prefix.resize(n,0);
        dp.resize(n,vector<int>(n,-1));
        prefix[0]=stoneValue[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+stoneValue[i];
        }
        return rec(0,n-1,stoneValue);
    }
};