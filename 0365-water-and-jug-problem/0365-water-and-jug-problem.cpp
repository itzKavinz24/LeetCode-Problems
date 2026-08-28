class Solution {
public:
    int gc(int a,int b){
        if(b==0)return a;
        return gc(b,a%b);
    }
    bool canMeasureWater(int x, int y, int target) {
        if(target==0)return true;
        if(target > x + y)return false;
        int g= gc(x,y);
        return (target%g==0);
    }
};