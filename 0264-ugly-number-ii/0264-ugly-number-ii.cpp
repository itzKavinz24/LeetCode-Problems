class Solution {
public:
    int nthUglyNumber(int n) {
        if(n<=6)return n;
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        unordered_set<long long>st;
        pq.push(1);
        st.insert(1);
        int count =1;
        while(count!=n){
            long long curr = pq.top();pq.pop();
             count++;
            long long a = curr * 2;
            long long b = curr * 3;
            long long c = curr * 5;

            if(!st.count(a)){
            pq.push(a);
            st.insert(a);
        }
            if(!st.count(b)){
            pq.push(b);
            st.insert(b);
            }
            if(!st.count(c)){
            pq.push(c);
            st.insert(c);
            }
           
        }
        return pq.top();
    }
};