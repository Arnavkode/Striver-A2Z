class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int pos =0;
        int neg = 1;
        vector<int> ans(nums.size(), 0);
        for(auto num : nums){
            if(num/abs(num) == 1 ){ // positive

                ans[pos] = num;
                pos += 2;

            }
            if(num/abs(num) == -1 ){ // negative

                ans[neg] = num;
                neg += 2; //Skip to next odd index

            }
        }


        

        return ans;
        
    }
};


// the positive and negative numbers have to be saved somewhere in my understanding and then interleaved
// a vector is not better than a queue or a stack for storing those same sign integers
// what if we store only one interger and freeball with the other??
// push positives into the ans array directly and storw negatives
// push positves only when the size of the answer array has been even? (makes sense as a negative number is added after each positive)
// what if we encounter a lot of positive numbers without a negative hmmmmm (DEADEND HERE)

// OH dumb shit, i can directly place all the positive integers at even indexes and negative at odd indexes
// maintain two index pointers for that
