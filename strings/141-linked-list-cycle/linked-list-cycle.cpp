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
        if(head->next == nullptr) return false;
        ListNode* tort = head;
        ListNode* hare = head;

        while(hare != nullptr && hare -> next!= nullptr){
            hare = hare->next->next;
            tort = tort->next;
            if(hare == tort) return true;
        }

        return false;

        
    }
};

// acc to example the cycle could easily be searched with the help of if theres no null ptr
// the first approach was to maintain a hashp mao and if i see a node again il lstop traversing
// if the final curr ptr after traversing is pointing to null, the i  have no loop
// but if it points to smthg else then i dont have a loop
// but this bad soln as per tc and sc

// if i had a length parameter, we could have had timed loop to look for nullptr

// OKAY I saw TWO pointer in a soln title, major help 
// tortoise hair hi hai bc
