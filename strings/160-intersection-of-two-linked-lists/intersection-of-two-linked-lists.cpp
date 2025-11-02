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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    unordered_map<ListNode*, int> freq;
    ListNode* curr = headA;
    while(curr){
        freq[curr]++;
        curr = curr -> next;
    }
    curr = headB;
    while(curr){
        if(freq.count(curr) == 1) break;
        else curr = curr -> next;
    }

    return curr;
        
    }
};

// need to find the intersection point of two linked lists
// normal inuitition would be to compare very address in L1 with L2 but that seems like
// a bad idea for longer lists

// maintaining two pointers but for?
// could use a frequency map for pointers, tbh shoud implement that
