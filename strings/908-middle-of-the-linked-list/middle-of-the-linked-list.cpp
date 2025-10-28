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
    ListNode* middleNode(ListNode* head) {

        if(head->next == nullptr) return head;

        ListNode* tort = head; //moves one
        ListNode* hare = head; //moves two
        

        while(hare != nullptr && hare->next != nullptr){
            tort = tort -> next;
            hare = hare->next->next;
        }

        return tort;
        
        
    }
};

// classic rabit and hare problem, make one go a step and the second one go two steps
// the first one would give the middle, or mid+1 when the scond one reaches nullptr