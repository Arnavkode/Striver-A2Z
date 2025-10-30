/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {

            if(head == nullptr) return false;
        vector<int> pal;
        ListNode* curr = head;

        while(curr != nullptr){
            pal.push_back(curr->val);
            curr = curr->next;
        }


        if(pal.size()%2 == 0){ //is even

            int mid1 = (pal.size() - 1)/2;
            int mid2 = (pal.size() - 1)/2 + 1;

            while(mid1 >=0 && mid2 < pal.size()){
                if(pal[mid1] != pal[mid2]) return false;
                mid1--;
                mid2++;
            }
            return true;

        }
        else{
            int mid = (pal.size() - 1)/2;
            int left = mid;
            int right = mid;

            while(left >-1 && right < pal.size()){
                if(pal[left] != pal[right]) return false;
                left--;
                right++;
            }

            return true;

        }
        
    }
};

// okay palindrome test
// lets check, the dumb dumb way to do it is traverse the ll and then store each in an array then check for palindrome
// might do this first
