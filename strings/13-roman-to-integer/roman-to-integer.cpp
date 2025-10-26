class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> list;
        list['I'] = 1;
        list['V'] = 5;
        list['X'] = 10;
        list['L'] = 50;
        list['C'] = 100;
        list['D'] = 500;
        list['M'] = 1000;
        int n =s.size();
        if(s.size() == 1) return list[s[0]];
        int result = 0;
        for(int i = 1; i<s.size(); i++){
            if(list[s[i-1]] >= list[s[i]]) result += list[s[i-1]];
            else result -= list[s[i-1]];
        } //this doesnt account the last character

        result += list[s[n-1]];

        return result;
        
    }
};

// given a roman string, if greater is placed before lower then we add 
// when lower is placed before greater then we subtract
// there exists a precedency list tho
// 