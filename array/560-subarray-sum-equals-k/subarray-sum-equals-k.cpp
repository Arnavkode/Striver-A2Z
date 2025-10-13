class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {


        // sort karna doesnt work as [1,2,1] has two subarrays but [1,1,2] has one subarray only, which is diff
        unordered_map<int, int> map;
        map[0] =1;
        // store the sum against how many times it has been found;

        int sum =0;
        int count = 0;
        for(int n : nums){
            sum += n;
            
            if(map.find(sum - k) != map.end()){
                 
                 count += map[sum-k];}
            map[sum]++;

        }
       
        return count;

    }
};

// brute force two loops
// kadane type shit can use
// sort
// maintain a first pointer to a number less than the target, if the next plus this is  = k then increaes counter
// else if increases, just move forward

// subtraction
// start with a hashmap and store sum until every index
// then check whether if the number that i get from subtracting k from that sum exists? basically sying
// yes theres a part of the array that exists without k, whihc meant that k existed within some elements of the array

