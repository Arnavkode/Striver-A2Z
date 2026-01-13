class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeroes = 0;
        int ones = 0;
        int twos = 0;

        for(int n: nums){
            if(n == 0) zeroes++;
            if(n == 1) ones++;
            if(n == 2) twos++;
        }
        int i = 0;
        while(zeroes >0){
            nums[i] = 0;
            i++;
            zeroes--;
        }  
        while(ones >0){
            nums[i] = 1;
            i++;
            ones--;
        }    
        while(twos >0){
            nums[i] = 2;
            i++;
            twos--;
        }      
    }
};