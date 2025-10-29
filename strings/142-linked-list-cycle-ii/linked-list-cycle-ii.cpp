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
        ListNode* tort = head;
        ListNode* hare = head;

        while(hare != nullptr && hare->next != nullptr){
            hare = hare->next->next;
            tort = tort->next;
            if(hare == tort){
                tort = head;
                while(tort!=hare){
                    tort = tort->next;
                    hare = hare->next;
                }
                 return tort;
            }
            
        } 
       return nullptr;
        
    }
};

// this can easily be done by map method, but im sure there must be a better method
// apparently this can also be done witht he help of tortoise hare but im confused how
// READ the proof for the second part