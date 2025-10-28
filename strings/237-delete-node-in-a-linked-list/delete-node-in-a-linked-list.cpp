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
    void deleteNode(ListNode* node) {

        auto next = node->next;
        *node = *next;
        // now node is overwritten with nexts value and it now points to wtv next points to
        delete next;
        
    }
};

// got a SLL
// we need to delete node
// need to maintain a last node

// ok this was very confusing on my own
// the solution says that i just copy the next node onto this one, which would mean
// that my curr node and the next node both point to the next to next node so if i delete the next node
// i maintain the order of the ll