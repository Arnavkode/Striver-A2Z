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


        if(headA == nullptr || headB == nullptr) return nullptr;
        int L1 = 1;
        int L2 = 1;

        ListNode* curr1 = headA;
        ListNode* curr2 = headB;

        while(curr1){
            L1++;
            curr1 = curr1 -> next;
        }
        while(curr2){
            L2++;
            curr2 = curr2 -> next;
        }

        int diff = abs(L2-L1);
        curr1 = headA;
        curr2 = headB;
        if(L1 > L2){
            while(diff--) curr1 = curr1-> next;

            while(curr1){
                if(curr1 == curr2) break;
                curr1 = curr1  ->next;
                curr2 = curr2 -> next;
            }
        }else{
            while(diff--) curr2 = curr2 -> next;

            while(curr2){
                if(curr1 == curr2) break;
                curr1 = curr1  ->next;
                curr2 = curr2 -> next;
            }
        }

        return curr1;
    }
};

// need to find the intersection point of two linked lists
// normal inuitition would be to compare very address in L1 with L2 but that seems like
// a bad idea for longer lists

// maintaining two pointers but for?
// could use a frequency map for pointers, tbh shoud implement that, not the best solution of course
// TC: O(N+M) SC: (N+M)

// what if i make a dummy node point to both of A and B ke head by making a whole ass new class lyasgo


// Best approach is to have the two pointers be at equal distance sfrom the end and then traversed until they meet
// 