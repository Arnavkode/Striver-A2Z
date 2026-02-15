class Solution {
public:
    string addBinary(string a, string b) {
        int size = max(a.size(), b.size());
        string ans;
        while(a.size() > b.size()){
            b.insert(0,1, '0');
        }
        while(b.size() > a.size()){
            a.insert(0,1,'0');
        }
        int carry = 0;
        for(int i =size-1; i >-1; i--){
            if(a[i] == '1' && b[i] == '1' && carry == 1){
                ans.insert(0,1,'1');
                carry  = 1;
            }
            else if(a[i] == '1' && b[i] == '1' && carry == 0){
                ans.insert(0,1,'0');
                carry = 1;
            }
            else if(a[i] == '1' && b[i] == '0' && carry == 1){
                ans.insert(0, 1,'0');
                carry = 1;
            }
            else if(a[i] == '0' && b[i] == '1' && carry == 1){
                ans.insert(0,1, '0');
                carry = 1;
            }
            else if(a[i] == '1' && b[i] == '0' && carry == 0){
                ans.insert(0,1, '1');
                carry = 0;
            }
            else if(a[i] == '0' && b[i] == '1' && carry == 0){
                ans.insert(0,1, '1');
                carry = 0;
            }
            else if(a[i] == '0' && b[i] == '0' && carry == 1){
                ans.insert(0,1, '1');
                carry = 0;
            }
            else if(a[i] == '0' && b[i] == '0' && carry == 0){
                ans.insert(0,1, '0');
                carry = 0;
            }
        }
        if(carry == 1){
            ans.insert(0,1,'1');
        }
        return ans;
        
    }
};