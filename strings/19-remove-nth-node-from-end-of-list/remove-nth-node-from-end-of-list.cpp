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

    void deletenode(ListNode* curr, ListNode* prev, int level, int n, int &depth){

        if(curr == nullptr){ depth = level - 1; return;}
        deletenode(curr->next, curr, level +1, n, depth );
        if(depth - level + 1 == n ){
            prev -> next = curr ->next;
            delete curr;
            return ;
        }
        
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int depth = 0;
        ListNode* prev = new ListNode(0);
        prev->next = head;
        deletenode(head, prev, 1,n, depth);

ListNode* newHead = prev->next;
        delete prev; // Clean up the dummy
        return newHead;
        
    }
};

// there is a recursive way for this for sure
// if i go deep while checking out levels okay i got something ig;