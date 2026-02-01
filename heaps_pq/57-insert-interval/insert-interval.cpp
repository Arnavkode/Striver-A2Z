class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        int start = newInterval[0];
        int end = newInterval[1]; //indexs
        int n = intervals.size();
        int i =0;
        vector<vector<int>> ans;
        while(i<n && intervals[i][1] < start){
            ans.push_back(intervals[i]);
            i++;
        }   
        int starti = 0;
        int endi = 0;

        while(i<n && intervals[i][0] <= end){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        ans.push_back(newInterval);

        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};

// the current approach would eb to make an auxillary array as anser
// secondly check the start and ends of each interval with our query interva;
// if just the start is included we traverse to find where the end is included
// if both are included then we just add the current interval tot he answer
