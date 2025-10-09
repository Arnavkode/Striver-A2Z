class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        queue<int> pos;
        queue<int> neg;

        for(auto num : nums){
            if(num/abs(num) == 1 ){ // positive

                pos.push(num);

            }
            if(num/abs(num) == -1 ){ // negative

                neg.push(num);

            }
        }

        vector<int> ans;

        while(!neg.empty()){


            ans.push_back(pos.front());  //begin with a positive integrer
            pos.pop();
            ans.push_back(neg.front());
            neg.pop();
        }

        return ans;
        
    }
};