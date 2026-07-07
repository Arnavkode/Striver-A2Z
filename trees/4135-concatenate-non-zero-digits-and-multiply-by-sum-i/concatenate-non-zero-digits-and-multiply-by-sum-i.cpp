class Solution {
public:
    long long sumAndMultiply(int n) {
        long long newNumber = 0;
        int sum = 0;
        int number = 0;
        while(n >= 1){
            int digit = n%10;
            if(digit == 0){n /= 10; continue;}
            sum += digit;
            newNumber = newNumber+ digit * pow(10, number);
            number++;
            n /= 10;

        }

        return sum * newNumber;
    }
};

// given am