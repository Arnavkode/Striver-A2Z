class Solution {
public:
    int jump(vector<int>& nums) {

        int farthest = 0;
        int n = nums.size();
        int currentend = 0;
        int jumps = 0;

        for(int i = 0; i< n-1; i++){
            farthest = max(farthest, i + nums[i]);

            if(i == currentend){ jumps++; currentend = farthest;};

        }
        return jumps;
        
    }
};

// okay need to return the minimum number of jumps
// need to check how many times is maxreach changed

// need to find the sortest path to raech a certain index
// uhm okay so dp solution is v slow

// i heard a greedy bfs
// so pruning a tree, if it reaches the jumpcount more than the current min