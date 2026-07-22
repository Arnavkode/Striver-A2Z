class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> sumfreq;
        sumfreq[0] =1;
        int sum = 0;
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];
            if(sumfreq.count((sum-k))){
                ans += sumfreq[(sum-k)];
            }
            sumfreq[(sum)]++;

        }

        return ans;
    }
};