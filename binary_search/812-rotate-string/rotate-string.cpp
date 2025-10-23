class Solution {
public:
    bool rotateString(string s, string goal) {

        int n = s.size();
        for(int i = 0; i< n; i++){
            if(s == goal ) return true;
            s+= s[0];
            s.erase(0,1);
        }
        return false;
    }
};

// to tell if the string s can become goal on some shifts
// basically should have the same number and same characters
// best practice would be to sort and give if equal
// O(nlogn)

// MAJOR : a shift and exchange are diff
// so O(n) to scan the first matching character then cyclically check subsequent
// i think i should look for break points?

// ok very dumb ans is just perform a shit for n times, any time it is equal to the goal
// we can return true 