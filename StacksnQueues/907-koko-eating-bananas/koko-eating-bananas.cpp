class Solution {
public:

    long long hoursreq(vector<int> & piles, int k){
        long long hours = 0;
        for(int p : piles){
            hours+= ceil((double)p/k);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int max = -1;
        for(int p: piles){
            if(p > max) max = p;
        }
        int high =  max;
        int ans = high; //if the loop never runs, the ans must be intitialised
        while(low<high){
            int mid = (low + high)/2;
            if(hoursreq(piles, mid) <= h){
                ans= mid;
                 high = mid;}
                 else{
                    low = mid + 1;
                 }
            
        }

        return ans;
        
    }
};
// need to return min
// maximum k can be the maximum number of bananas in a pile
// k is perhour eating speed
// need to find k such that she eats all bananas within h hours