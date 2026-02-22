class Solution {
public:
    int binaryGap(int n) {
        int gap = 0;
        int left = 0;
        string binary = bitset<32> (n).to_string();
        for(int i = 0; i<binary.size() ; i++){
            if(binary[i] == '1') {left = i; break;} 
        }
        for(int i = left ;i< binary.size(); i++ ){
            if(binary[i] == '1'){
                gap = max(gap, i - left );
                left = i;
            }
        }

        return gap;
    }
};