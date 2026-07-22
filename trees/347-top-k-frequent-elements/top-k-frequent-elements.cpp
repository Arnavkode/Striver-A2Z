class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<pair<int,int>> freq;
        int left =0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == nums[left]){
                count++;

            }else{
                freq.push_back({count, nums[left]});
                count = 1;
                left = i;
            }
        }

        freq.push_back({count, nums[left]});

        sort(freq.begin(), freq.end());
        reverse(freq.begin(), freq.end());

        vector<int> ans;

        for(int i = 0 ; i < k; i++){
            ans.push_back(freq[i].second);
        }
        return ans;

    }
};