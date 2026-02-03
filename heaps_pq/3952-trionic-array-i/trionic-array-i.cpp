class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int i = 1;
        int n = nums.size();
        if(nums[0] >= nums[1]) return false;
        while(i < n && nums[i] > nums[i-1]){ //inreasing
            if(i == n-1) return false;
            i++;

        }
        while(i < n && nums[i] < nums[i-1]){//decline
            if(i == n-1) return false;
            i++;

        }
        while(i <n && nums[i] > nums[i-1])i++;
        if(i == n) return true;
        else return false;
    }
};

// okay so trionic array is basically, having increase -> decrease -> increase
// can be achieved through differences?