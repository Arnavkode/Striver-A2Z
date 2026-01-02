class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int tgt = nums.size()/2;
        unordered_map<int, int> map;

        for(int n : nums){
            map[n]++;
        }

        for(pair<int,int> p: map){
            if( p.second == tgt) return p.first;
        }
        return -1;
    }
};

// n repeated elements 
// even sized array
// nums contains n+1 elements
// return the element that is repeated n times 