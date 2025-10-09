class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        // permutation is on the extremese : breaking point is not found (descending), breaking point is 
        // found at the start (ascending) 
        int n = nums.size();
        if (n < 2) return;

        // 1) find rightmost i with nums[i] < nums[i+1]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) --i;

        // 2) if not found, reverse whole array (last permutation -> first)
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // 3) find rightmost j > i with nums[j] > nums[i]
        int j = n - 1;
        while (nums[j] <= nums[i]) --j;

        // 4) swap and 5) reverse the suffix
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
    }
};

// permutations = all the possible arrangements of elements in an array
// lexicographically greater = [1,3,2] > [1,2,3]
// need to find the next lexicographical permutation in space

// brute force would be find all permutations then compare each, possible as low scalability of numbers
// there's an STL function for this next_permutation()
// a permutation with asceding sorted would be the smallest (1,2,3,4)
// a permuation with descending sort would be the largest (4,3,2,1)
// looking an intermediate permuations (1,2,4,3), next (1,4,2,3)
// finding a break point where the there exists an out of place larger element num[i] <num[i+1]
// swap i with the smallest integer larger than it in the roght half
// reverse the whole right half