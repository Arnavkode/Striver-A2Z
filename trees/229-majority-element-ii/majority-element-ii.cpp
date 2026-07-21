class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int threshold = floor(nums.size()/3);

       unordered_map<int,int> freq;
        vector<int> ans;
       for(int n : nums){
        freq[n]++;
       } 

       for(auto  p : freq){
        if(p.second > threshold) ans.push_back(p.first);
       }

       return ans;
    }
};