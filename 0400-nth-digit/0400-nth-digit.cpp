class Solution {
public:
    int findNthDigit(int n) {
        long long start =1 ;
        long long length = 1;
        long long digit = 9;
        while(length*digit < n){
            n = n - (digit*length);
            length++;
            digit*=10;
            start*=10;
        }
        long long number = start + (n-1)/length;
        int index = (n - 1) % length;
        string s = to_string(number);
        return s[index]-'0';

        
        
    }
};