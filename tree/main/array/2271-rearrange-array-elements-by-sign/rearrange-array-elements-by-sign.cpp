class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> pos;
        vector<int> neg;

        for(auto num : nums){
            if(num/abs(num) == 1 ){ // positive

                pos.push_back(num);

            }
            if(num/abs(num) == -1 ){ // negative

                neg.push_back(num);

            }
        }

        vector<int> ans;

        for(int i = 0; i<pos.size(); i++){


            ans.push_back(pos[i]);  //begin with a positive integrer
        
            ans.push_back(neg[i]);
            
        }

        return ans;
        
    }
};