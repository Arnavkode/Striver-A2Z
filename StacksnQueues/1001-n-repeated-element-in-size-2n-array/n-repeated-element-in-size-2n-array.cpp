class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

       unordered_set<int> seen;
       for(int n : nums){
        if(seen.count(n)){
            return n;
        }
        else seen.insert(n);
       }
       return -1;
        

    }
};

// n repeated elements 
// even sized array
// nums contains n+1 elements
// return the element that is repeated n times 
// used a freq map high runtime
// could cut short
// marginally beatt last runtime
// maximum unqiue numbers n+1
// use set apparently