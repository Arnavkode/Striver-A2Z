class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        int high = n-1;
        int low = 0;
        int mid;
        int missing;
        while(low<=high){
            mid = (low+high)/2;
missing = arr[mid] - (mid+1);
            if(missing < k) low = mid + 1;
            else high = mid-1;
        }
        return high + k +1;
    }
};

// check between number at highest and loweest index
// maybe maintain a hashmap to check further if a number is in the array or no

// difference between two consecutive numbers tells us the number of 

// the numbers starting from positive 1
// so 0th index must have 1, 1st index must have 2 and nth index must have n+1
// the numbers missing in between can be found by n+1 -n -1;
// so if its less than k go right else left