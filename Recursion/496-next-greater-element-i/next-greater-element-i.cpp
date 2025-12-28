class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        //okay what i can do is store if a greater element happens in th emap forward
        unordered_map<int,int> map;
        int size2 = nums2.size();
        for(int i = 0; i< size2; i++){
            for(int j = i ; j<size2; j++){
                if(nums2[j] > nums2[i]){
                    map[nums2[i]] = nums2[j];
                    break;
                }
                else{
                    map[nums2[i]] = -1;
                }
            }
        }
        vector<int> ans;
        for(int num: nums1){
            ans.push_back(map[num]);
        }

        return ans;
    }
};
// okhy next greater element
// two distinct arrays given 
// nums1 is a subset of nums2
// okay so for every element in nums1, i need to find the next greatest in nums2
// if not -1 then

// could sort then just get the next
// do loop toh chalana padega bro

// ans has an unordered map which was lowk i thoguht would exist, but oaky