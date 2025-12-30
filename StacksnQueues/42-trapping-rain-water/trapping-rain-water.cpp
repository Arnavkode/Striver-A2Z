class Solution {
public:
    int trap(vector<int>& height) {

        // so what will happen is ill have a right index that iterates aage, ill have  
        // left index that would define the left wall
        // also ill have a the mid index that is in betweent the two walls
        // all of them taken out one by one by the stack
        int ans = 0;
        stack<int> stk;
        for(int right = 0; right<height.size() ; right++){
            while(!stk.empty()&& height[right] > height[stk.top()]){
                int midindex = stk.top();
                stk.pop();

                // if i reach an edge here, ill just give up
                if(stk.empty()) break;

                int leftindex = stk.top();

                int h = min(height[leftindex], height[right]) - height [midindex]; //okay need to find the heigh from whichever walls the shortest
                int width = right - leftindex - 1;
                ans += h * width;

            }
            stk.push(right);
        }

        return ans;
    }

};

// okay just did nge
// could see a pettern here
// from every block that is high, need to store th enumber of blocks in between each more or equal
// then sub them from the multiply

// okay the stack approach says that, i need to se tmy foot on a left, then 