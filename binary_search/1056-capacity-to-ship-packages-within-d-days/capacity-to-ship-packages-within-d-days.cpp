class Solution {
public:
    bool doesCapacityWork(vector<int>& weights, int days, int cap){

        int daysreq = 1;
        int full = cap;
        for(int n : weights){
            if(cap - n <0){
                daysreq++;
                cap = full;

            }
            cap -= n;
        }
        if(daysreq > days) return false;
        else return true;

    }
    int shipWithinDays(vector<int>& weights, int days) {


        int low = 1;
        // te fastest we can get all the packages done is in one day, when the capacity is the sum of all weights
        int high = 0;
        for(int n : weights){
            low = max(low, n);
            high += n;
        }
        int mid;
        while(low<=high){
            mid = (low +high)/2;
            if(doesCapacityWork(weights, days, mid)) high = mid -1; // lower the capacity the more the days req
            else low = mid+1;
        }
        return low;
        
    }
};

// weights give the weight of the ith package
// to find out the minimum capacity of the ship so that all the packages are shipped within days
// 
