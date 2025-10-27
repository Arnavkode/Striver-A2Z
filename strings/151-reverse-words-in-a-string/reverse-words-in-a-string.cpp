class Solution {
public:
    string reverseWords(string s) {

        string ans;
        vector<string> strings;
        string temp;
        for(char c: s){
            if(c == ' '){
                if(!temp.empty()){strings.push_back(temp);}
                 temp.clear();
                 }
            else{
                temp += c;
            }
        }
strings.push_back(temp);
        

        reverse(strings.begin(), strings.end());

        for(string str : strings){
            ans += str;
            ans += ' ';
        }

    
        int left = 0;
        int right = ans.size()-1;

        while(ans[left] == ' ')left++;
        while(ans[right] == ' ')right--;
        return ans.substr(left, right - left +1 );

        
    }
};

// i could store all the strings in a vector, reverse that vector and append it to the ans