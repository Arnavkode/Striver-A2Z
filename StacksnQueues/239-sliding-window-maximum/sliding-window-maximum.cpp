class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        vector<int> ans;
        deque<int> q;
        

        for(int i = 0 ;i < nums.size() ; i++){
            // pop all eelements from the front that are out of wndow range
            while(!q.empty() && q.front() <= i - k){
                q.pop_front();
            }
            // pop all elements from the back that are  less than the current element
            while(!q.empty() && nums[q.back()] < nums[i] ){
                q.pop_back();
            }
            q.push_back(i);

            if(i >= k-1 ) ans.push_back(nums[q.front()]);
        } 

        return ans;
    }
};

// need to return the max every k terms 

// brute force done, TLE

// my slime thought that i coud do it with monostack, i waas dumb
// if i have a slidign window, its better to have queue
// is it greater than the ohter seen thus far? should be my queestion

// deque proposes a timeline, the elements in front might be old so they need to be checked 
// for out of range issues
// the back ones proposes the heirarchy