class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        int maxe = 0;
        int mine = INT_MAX;

        for(int n: nums){
            maxe = max(n, maxe);
            mine = min(n, mine);
        }

        return gcd(maxe, mine);
    }
};