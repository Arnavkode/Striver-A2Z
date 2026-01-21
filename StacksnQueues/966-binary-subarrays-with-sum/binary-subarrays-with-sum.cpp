class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // kinda like two sum

        // okay the two pointer problem is kinda ass, cuz acc to gemini it can be solved using prefix sum
        // i think its better to use prefix sum when dealing with problems where i have a sum and i have to 
        // find ALL ARRAYS

        int left = 0;
        int currsum = 0;
        int ans =0;
        unordered_map<int,int> prefix; //prefix seum against its frequency
        prefix[0] = 1;
        for(int n : nums){
            currsum += n;
            
            if(prefix.count(currsum - goal)){
                ans += prefix[currsum - goal];
            }
            prefix[currsum]++;
        }

        return ans;

        
    }
};

// i have a binary array and a target
// need to return all non empty arrays with that sum