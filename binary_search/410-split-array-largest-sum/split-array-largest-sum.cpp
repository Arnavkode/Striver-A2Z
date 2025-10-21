class Solution {
public:

    bool isPossible(vector<int>& nums, int k, int limit){
 int sum = 0;
            int splits = 1;

            // need to assign at max limit integers to a split, if i can do it in less than k splits then its good otherwise no
           
            for(int n : nums){
                if(n > limit) return false;
                if(sum + n > limit){
                    sum = n;
                    splits++; //start a new split
                }
                else{
                    sum += n;
                }
            }


        
                    return splits <= k;
    }

    
    int splitArray(vector<int>& nums, int k) {

        
        int maxi = INT_MIN;
        for(int n : nums){
            maxi = max(n, maxi);
        }
        int low = maxi;
        int high = accumulate(nums.begin(), nums.end(), 0LL);

        int mid;

        while(low<= high){

            mid = (low +high)/2;
            if(isPossible(nums, k , mid)) //if possible then lets try to go minimise it even more
            {
                high = mid - 1;

            }
            else low = mid +1 ;
        }
        return low;
       
        
    }
    
};