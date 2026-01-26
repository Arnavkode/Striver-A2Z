class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {

        vector<vector<int>> ans;

        sort(arr.begin(), arr.end());

        int left = 0;
        int mindiff = INT_MAX;
        
        //if the current right is giving me a larger diff then i can just go ahead with my left
        for(int right = 1; right < arr.size() ; right++ ){
            int currdiff = abs(arr[right] - arr[right - 1]);
            mindiff = min(currdiff, mindiff);
        }
        for(int right = 1; right < arr.size() ; right++ ){
            int currdiff = abs(arr[right] - arr[right - 1]);
            if(currdiff == mindiff) ans.push_back({arr[right-1] , arr[right]});
        }

        return ans;


        
    }
};

// minimum fucking absolute difference
// okay so any minmimum diff the pairs need to stored