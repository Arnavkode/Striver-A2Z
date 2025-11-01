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
    ListNode* deleteMiddle(ListNode* head) {

        if(head == nullptr) return nullptr;
        if(head -> next == nullptr) return nullptr;
        

        ListNode* hare = head;
        ListNode* tort = head;

        while(hare != nullptr && hare->next != nullptr){
            hare = hare -> next-> next;
            tort = tort -> next;
        }

        ListNode* back = head;

        while(back -> next != tort){
            back = back->next;
        }

        back -> next = tort->next;
        delete tort;
        return head;

        

    }
};

// kill the tortoise basically ig