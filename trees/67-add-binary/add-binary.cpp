class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        // Iterate while there are digits left in a, b, OR there is a carry
        while(i >= 0 || j >= 0 || carry == 1) {
            int sum = carry;
            
            // Add bit from a if available
            if(i >= 0) {
                sum += a[i] - '0'; // Convert char '1' to int 1
                i--;
            }
            
            // Add bit from b if available
            if(j >= 0) {
                sum += b[j] - '0';
                j--;
            }

            // If sum is 2 (1+1), we append '0' and carry 1
            // If sum is 3 (1+1+1), we append '1' and carry 1
            ans += to_string(sum % 2);
            carry = sum / 2;
        }

        // The answer is currently backwards because we appended
        reverse(ans.begin(), ans.end());
        return ans;
    }
};