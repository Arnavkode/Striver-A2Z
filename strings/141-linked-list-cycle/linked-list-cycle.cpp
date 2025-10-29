/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head == nullptr) return false;
        ListNode* curr = head;

        // could get a map of addresses
        unordered_map<ListNode*, int> mp;

        while(curr->next != nullptr && mp.count(curr -> next) == 0){
            mp[curr]++;
            curr = curr -> next;
            
        }
        if (curr-> next == nullptr) return false;
        else return true;
        
    }
};

// acc to example the cycle could easily be searched with the help of if theres no null ptr
