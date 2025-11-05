class Solution {
public:

    double helper(double n, long long pow){

        if(pow == 0) return 1;
        
        double half = helper(n, pow/2);

        if(pow% 2 == 0){
            return half * half;
        }
        else return n * half * half;
    }
    double myPow(double x, long long n) {
        double ans = helper(x,abs(n));
        if(n <0) return 1/ans;
        else return ans;
    }
};

// ok i took some help
// essentially the approahc is bianry exponentiation
// mtlb ki if the n is even then x^n = (x^2)^(n/2);
// else if its odd then x * (x^(n-1)/2)^2
// hence halfing the recursion tree in half.