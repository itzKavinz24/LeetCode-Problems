class MedianFinder {
public:
  multiset<int>asc;
    multiset<int,greater<int>>desc;  
    MedianFinder() {
        
    }
    void balance(){
         int n=desc.size(),m =asc.size();
         if(n-2==m){
            asc.insert(*desc.begin());
            desc.erase(desc.begin());
            
         }if(m>n){
            desc.insert(*asc.begin());
            asc.erase(asc.begin());
         }
        
    }
    void addNum(int num) {
        if(*desc.begin() >= num || desc.size()==0){
            desc.insert(num);
        }else{
            asc.insert(num);
        }
        balance();
        
    }
    
    double findMedian() {
        if(desc.size() > asc.size()){
            return *desc.begin();
        }
        return ((double)*desc.begin() + *asc.begin())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */