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
        hare = hare -> next -> next;
        while(hare != nullptr && hare->next != nullptr){
            hare = hare -> next-> next;
            tort = tort -> next;
        }

        ListNode* del = tort ->next;
        tort->next = del->next;
        delete del;
        return head;

        

    }
};

// kill the tortoise basically ig

// instead of runnign naother loop to find the prev to the mid node
// what i can do is increment fast before and then run the tort and har loop, what this would do is
// land the tort one before the mid node