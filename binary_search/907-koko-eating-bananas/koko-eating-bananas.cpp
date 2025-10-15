class Solution {
public:

    long long hoursreq(vector<int>& piles, int k){
        long long hours = 0;
        for(int p : piles){

            hours += ceil((double)p/k);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxk = -1;
        int mink = INT_MAX;

        for(int p : piles){
            maxk = max(maxk, p);
            mink = min(mink, p);
        }

        int low = 1;
        int high = maxk;
        int mid;


        while(low<=high){
            mid = (low + high)/2;
            if(hoursreq(piles, mid) > h) low = mid+1;//would need to decrease k
            else high = mid - 1;
        
        }

        return low;
    }
};

// piles array has no. of bananas in ith pile
// guards will come back in h hours
// each hour koko chooses a pile of bananas and eats k no. of bananas from it
// need to find the minimum number of k to eat all bananas
// high would be the ceil of k which can be max in piles
// low would be 0
// would need to make a helper functio to evaluate if actually k would wokr in h hours
// TBH i will need to evaluate the number of hours (h) it would take with current k 
// so if number of hours with current k is mroe than h we'd need to increase k

// tc: O(nlogn) for each mid function of O(n) is called thas why
// sc : O(1)