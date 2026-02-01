class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;
        int ans = 0;
        sort(intervals.begin(), intervals.end());
        int prevend = intervals[0][1];

        for(int i = 1; i< n ;i ++){
            // if my current interval ends in the next interval
            if(prevend > intervals[i][0]){ //if my preious ended after the next interval started
                //they overlap
                ans++;
                prevend = min(prevend, intervals[i][1]); //keeping the interval with the lower duration
                // because larger itnervals may cayse more problems later
            }
            else prevend = intervals[i][1];
            // else is used because were asked how many should we remove
            // i fwe just count the number of currently overlapping intervals, we can remove them and
            // bring peace to our result
            // 
        }

        return ans;
        
    }
};

// so basically count the number of overlapoing arrays