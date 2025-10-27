class Solution {
public:

    string checkCentre(string s, int centre1, int centre2){

        int n = s.size();
        int left = centre1;
        int right = centre2;
        int maxlen = 0;
        string maxstr;
        while(left>=0 && right<n){

            if(s[left] == s[right]){
                
                maxlen = max(maxlen, right- left +1);
                maxstr = s.substr(left, maxlen);
                left--;
                right++;
            }
            else break;
        }
        return maxstr;

    }
    string longestPalindrome(string s) {

        int n = s.size();
        string maxstr;
        for(int centre = 0; centre < n; centre++){

            string evenlen = checkCentre(s, centre, centre+1);
            string oddlen = checkCentre(s, centre, centre);
            int maxlen = max(evenlen.size() , oddlen.size());
            if(maxlen > maxstr.size()){
                evenlen.size() > oddlen.size() ? maxstr = evenlen : maxstr = oddlen;
            }
            
        }      
        return maxstr;  
    }
};

// i have been given a substrign and i need to find the longest palindromic substring
// uhm how do i do that?
// go over each substring?
// read the solution, my understanding says that to tackle with both oddlength and evenlength 
// give the function a centre go back from one and go forward and constantly check for presene
// of a palindrome, return the length choose the max.

