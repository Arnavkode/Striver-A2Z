class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;

        int size = digits.size();
        for(int i = size - 1; i > -1; i--){
            if(digits[i] <9){
                digits[i]++;
                return digits;
            }
            else{
                digits[i] = 0;
            }
        }
        digits.insert(digits.begin(), 1);
       
        return digits;

    }
};

// basically an adder