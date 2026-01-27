class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        // two loops?
        // uhm i dont think needed

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int j = 0;
        int i =0;
        int ans = 0;
        int size = min(s.size(), g.size());

        while( i< s.size() && j< g.size()){
            if(s[i] >= g[j]){
                ans++;
                i++;
                j++;
            }else{
                i++;
            }
        }


        return ans;
        
    }
};

// g is greed and, s gives cookie size
// maximuse the number of content children