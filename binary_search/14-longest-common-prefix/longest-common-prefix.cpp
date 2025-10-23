class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();
        int minsize = INT_MAX;
        for(int  i = 0; i< n; i++){
            int x= strs[i].size();
            minsize = min(minsize, x);
        }
        string ans;
        for(int  j = 0 ; j<minsize ; j++){
            bool diff = false;
            char last = strs[0][j];
            for(int i = 0 ; i<n ; i++){
               if(strs[i][j] != last){
                diff = true;
                break;
            
               } 
            }
            if(!diff) ans.append(1, last); 
            else break;
        }
        return ans;
    }
};

// need to find the longest common prefix?
// just iterate over all and break on the first instance of not common
// firs tapproach is O(n) only?? no to go with all ill need O(n2)
// 