class Solution {
public:
    string frequencySort(string s) {

        
        unordered_map<char,int> mp;
        // make a frequency map
        for(char c : s){
            mp[c]++;
        }
        // sort it
        priority_queue<pair<int,char>> pq;
        for(auto p : mp){
            pq.push({p.second, p.first});
        }

        string ans;
        while(!pq.empty()){
            pair p = pq.top();
            pq.pop();
            for(int i =0 ; i<p.first; i++){
                ans.append(1,p.second);
            }

        }
        return ans;
    }
};

// a string is given
// i need to sort in order of frequency
// descending?
// first apporach could be use a hashmap to maintain a record of frequency then just do it?
// will have to iterate twice loops

// i think the map should be frequency to a vector of characters
// sort and add s