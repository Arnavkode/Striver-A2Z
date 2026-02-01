class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return intervals;
        vector<vector<int>> ans;
        
        sort(intervals.begin() , intervals.end());
        vector<int> currentInterval = intervals[0];
        for(int i = 1 ;i < n ; i++){
            if(intervals[i][0] <= currentInterval[1]) //curr ends after the next start 
            {
                currentInterval[1] = max(currentInterval[1], intervals[i][1]) ;//so we merge them both 
            }
            else{
                ans.push_back(currentInterval);
                currentInterval = intervals[i];
            }

        }
        ans.push_back(currentInterval);
        return ans;
    }
};
// i wished i would have gone on a trip
// sanity lose hoti ja rahi hai iss campus mai din ke baad din
// merge overlapping intervalss