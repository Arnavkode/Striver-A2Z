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
    ListNode *detectCycle(ListNode *head) {

        if(head == nullptr) return nullptr; 
        unordered_map<ListNode* ,int> mp;

        ListNode* curr = head;

        while(curr -> next != nullptr && mp[curr] == 0){
            mp[curr]++;
            curr = curr->next;
        } 

        if(curr->next == nullptr) return nullptr;
        else return curr;
        
    }
};

// this can easily be done by map method, but im sure there must be a better method