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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        int carry = 0;
        while(curr1 != nullptr | curr2 != nullptr | carry != 0){
            int val1 = (curr1 != nullptr)? curr1 -> val : 0;
            int val2 = (curr2 != nullptr)? curr2 -> val : 0;

            int temp = val1 + val2  + carry;

            int digit = temp  %10;
            
            carry = (temp/10)%10;

            tail -> next = new ListNode(digit);
            tail = tail -> next;
            if(curr1) curr1 = curr1 -> next;
            if(curr2) curr2 = curr2 -> next;

        }

        return head -> next;
        
    }
};

// add two numbers
// will have to look out for carry
// figure carry out