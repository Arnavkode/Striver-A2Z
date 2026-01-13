class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> hash;
        // okay so i need to store the indexes

        for(int i = 0; i<nums.size() ;i++){
            hash[nums[i]] = i; //storing index against value
        }

        for(int i =0 ; i< nums.size() ; i++){
            int comp = target - nums[i];
            if(hash.count(comp) && hash[comp] != i){ //for self index check
                return{hash[comp] , i};
            }
        }

        return {};
    }
};


// so basically were checking if the complement exists of the current number int he table