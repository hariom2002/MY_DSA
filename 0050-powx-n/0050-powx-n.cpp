class Solution {
public:
    double myPow(double x, int n) {
        
        double res = 1.0;
        long nm = n;
        if(nm<0) nm = -1*nm;

        while(nm>0){
            if(nm%2==1){
                res = res*x;
                nm--;
            }
            else{
                x = x*x;
                nm/=2;
            }
        }
        if(n<0) return ((double)1/ (double)res);
        return res;
    }
};