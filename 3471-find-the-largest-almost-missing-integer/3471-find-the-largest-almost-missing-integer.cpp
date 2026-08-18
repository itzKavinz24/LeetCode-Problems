class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
         int n = nums.size();
         unordered_map<int,int>freq,freq2;
         int l=0,r=0;
        for(int r=0;r<nums.size();r++){
            freq[nums[r]]++;
            while(r-l+1>k){
                freq[nums[l]]--;
                if(freq[nums[l]]==0){
                    freq.erase(nums[l]);
                }
                l++;
            }
           if (r - l + 1 == k) {
            for (auto &p : freq) {
                    freq2[p.first]++;
                }
            }

        }
        int ans=-1;
        for(int num:nums){
            if(freq2[num]==1){
                ans=max(ans,num);
            }
        }
        return ans;

    }
};