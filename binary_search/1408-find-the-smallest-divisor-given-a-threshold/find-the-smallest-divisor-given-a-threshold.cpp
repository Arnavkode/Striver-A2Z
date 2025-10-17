class Solution {
public:
    int findSum(vector<int>& nums, int div){
        int sum = 0;
        for(int n : nums){
            sum += (ceil((double)n/div));

        }

        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {

        int n = nums.size();
        int low = 1;
        // we'll have to take max as high cuz the smallest sum we can get is n (numberof elements)
        int maxi  = -1;
        for(int n: nums){
            maxi = max(n, maxi);
        }
        int high = maxi;

        int mid;

        while(low<=high){
            mid = (low+high)/2;
            if(findSum(nums, mid) > threshold) low = mid + 1;
            else high = mid - 1;
        }

        return low;

        
    }
};

// an array of numbers is given
// a threshold is given, which is the sum of all the results of division of an entire array with a number
// need to find the smallest divisor such that the sum is less than or equal to the threshold

// from examples the higher the divisor the lower the sum

// TC: (nlogn)
// SC: O(1)

// further optimizatiions:
// apaprently ceil uses runtime
// so (n+div+1)/div
