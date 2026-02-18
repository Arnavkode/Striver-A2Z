class Solution {
public:
    bool hasAlternatingBits(int n) {
        string binary = bitset<31> (n).to_string();
        int counter = 0;
        size_t firstOne = binary.find('1');
        if (firstOne == string::npos) return true; // Case for 0
        
        // 2. Check neighbors
        for (int i = firstOne + 1; i < binary.size(); i++) {
            // If current char is same as previous, we failed
            if (binary[i] == binary[i-1]) return false;
        }
        return true;
    }
};