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

    void reverseLL(ListNode* node, ListNode* ptr){
        if(node -> next != nullptr){
            reverseLL(node->next, node);
        }

        node->next = ptr;
        return;
        
    }
    ListNode* reverseList(ListNode* head) {

        ListNode* curr = head;
        // ListNode* prev = nullptr;
        // ListNode* nexttemp;

        // maintain next prev and current

        // while(curr != nullptr){
        //     nexttemp = curr->next;
        //     curr-> next = prev;
        //     prev= curr;
        //     curr = nexttemp;
        // }

        if(head == nullptr) return nullptr;

        while(curr->next != nullptr){
            curr = curr -> next;
        }
        reverseLL(head, nullptr);


        return curr;

        
        
    }
};

// need to reverse the linked list
// go to last
// make it point to prev ig. lets try

// to do it recursively is okay. i can think of a function
// that would take in a node and terminate on if the next to that node is a null ptr