class Solution {
public: 
    multiset<int>asc;
    multiset<int,greater<int>>desc;

    void balance(){
        int n=desc.size(),m=asc.size();
        if(n-m>1){
            asc.insert(*desc.begin());
            desc.erase(desc.begin());
        }
        if(m>n){
            desc.insert(*asc.begin());
            asc.erase(asc.begin());
        }
    }
    double getmedian(){
        if(desc.size()>asc.size()){
            return *desc.begin();
        }
        return ((double)*desc.begin() + *asc.begin())/2.0;
    }
    void remove(int num){
        if(desc.find(num)!=desc.end()){
            desc.erase(desc.find(num));
        }else{
            asc.erase(asc.find(num));
        }
    balance();
    }
    void add(int num){
        if(desc.empty() || num<= *desc.begin()){
            desc.insert(num);
        }else{
            asc.insert(num);
        }
        balance();
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>res;
        int n=nums.size();
        for(int i=0;i<k;i++){
            add(nums[i]);
        }
        res.push_back(getmedian());
        for(int j=k;j<n;j++){
            remove(nums[j-k]);
            add(nums[j]);
            res.push_back(getmedian());
        }
        return res;
    }
};