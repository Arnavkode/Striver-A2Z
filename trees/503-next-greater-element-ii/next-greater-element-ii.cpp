class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        vector<int> ans(nums.size());

        for(int i =nums.size() -1 ; i >= 0 ; i--){
            while(!stk.empty() && stk.top() < nums[i]) stk.pop();

            stk.push(nums[i]);
        }
        for(int i =nums.size() -1 ; i >= 0 ; i--){
            while(!stk.empty() && stk.top() <= nums[i]) stk.pop();
            if(!stk.empty()) ans[i] = stk.top();
            else ans[i] = -1;
            stk.push(nums[i]);
        }

        return ans;
    }
};