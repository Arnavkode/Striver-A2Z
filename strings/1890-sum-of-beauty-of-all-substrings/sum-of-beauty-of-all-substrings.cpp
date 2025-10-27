class Solution {
public:

    
    int beautySum(string s) {
        
        int beautySum = 0;

        int n = s.size();

        for(int i =0 ; i<n ; i++){
            unordered_map<char,int> freq;

            for(int j = i ; j<n ;j++){
                freq[s[j]]++;

                int minf = INT_MAX;
                int maxf  =INT_MIN;

                for(auto p : freq){
                    minf = min (minf, p.second);
                    maxf = max(maxf, p.second);
                }
                beautySum += maxf - minf;
            }
        }

        return beautySum;
    }
};

// beauty of a substring is the diff between the most and least freuwnt element
// need to return the sum of beauties of all substrings
// 