class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;

        for(int i =0;i<s.size(); i++){
            map1[s[i]]++;
            map2[t[i]]++;
        }

        

        for(auto p : map1){
            if(map1[p.first] != map2[p.first]) return false;
        }
        return true;
    }
};

// Anagram = word derived by jumbling another word
// sort technique is O(nlogn)
// could use two maps