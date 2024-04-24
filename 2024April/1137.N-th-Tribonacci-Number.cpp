class Solution {
public:
    int tribonacci(int n) {
        if(n<=1) return n;
        if(n==2) return 1;
        
        int last_third = 0, last_second = 1, last = 1;
        int tn = 0;
        for(int i=3;i<=n;i++){
            tn = last + last_second + last_third;
            last_third = last_second;
            last_second = last;
            last = tn;
        }
        return tn;
    }
};