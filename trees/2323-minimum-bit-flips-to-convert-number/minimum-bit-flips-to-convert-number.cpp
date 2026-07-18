class Solution {
public:
    int minBitFlips(int start, int goal) {
        long long diff = start ^ goal;
        int count = 0;
        
        while(diff != 0){
            if((diff & 1) == 1) count++;
            diff = diff >> 1;
        }
        return count;
    }
};