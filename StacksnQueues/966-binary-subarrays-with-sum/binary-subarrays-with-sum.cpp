class Solution {
public:

    int helper(vector<int> & nums, int goal){
        if(goal<0) return 0;
        int left = 0;
        int currsum =0;
        int ans =0 ;

        for(int right = 0; right < nums.size() ; right++){
            currsum += nums[right];

            while(currsum > goal){
                currsum = currsum - nums[left];
                left++;
            }

            ans += (right - left +1);
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // kinda like two sum

        // okay the two pointer problem is kinda ass, cuz acc to gemini it can be solved using prefix sum
        // i think its better to use prefix sum when dealing with problems where i have a sum and i have to 
        // find ALL ARRAYS

        return helper(nums, goal) - helper(nums, goal - 1);

        
    }
};

// i have a binary array and a target
// need to return all non empty arrays with that sum

// I DONT UNDERSTAND TS

// but this approach has a time complexity of O(N)

// a better approach seen was, that subtract the number of arrays that have sum at most n
// from the number of arrays that have sum at most n-1