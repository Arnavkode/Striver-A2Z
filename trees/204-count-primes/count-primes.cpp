class Solution {
public:
    int countPrimes(int n) {
        vector<int> numbers(n, 0);
        if(n < 2) return 0;
        int ans = 0;
        numbers[0] = 1;
        numbers[1] = 1;
        for(int i = 2 ;i  < numbers.size() ; i++){
            for(int j = i + i ; j < numbers.size() ; j += i){
                numbers[j] = 1;
            }
        }

        for(int n : numbers){
            if(n == 0) ans++;
        }

        return ans;
    }
};
// the number of primes
// can nlogn