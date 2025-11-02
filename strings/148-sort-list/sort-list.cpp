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

    ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast -> next -> next;
        while(  fast != nullptr && fast -> next != nullptr){
            fast =  fast -> next -> next;
            slow = slow -> next;
        }



        return slow;
    }

    ListNode* mergeLL(ListNode* list1, ListNode* list2){

        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* head = new ListNode(-1);
        ListNode* temp = head;

        while(head1 && head2){
            if(head1->val > head2->val){
                temp -> next= head2;
            
                head2 = head2 -> next;
            }
            else{
                temp -> next= head1;
                head1 = head1 -> next;
            }

            temp = temp-> next;
        }

        while(head1){temp -> next= head1;
                head1 = head1 -> next;
                temp = temp-> next;
        }
        while(head2){
                            temp -> next= head2;
                head2 = head2 -> next;
                temp = temp -> next;
        }
        head = head->next;
        return head;
    }
    ListNode* sortList(ListNode* head) {

        if(head == nullptr) return nullptr;
        if(head-> next == nullptr) return head;

        ListNode* left = head;
        ListNode* middle = findMid(head);
        ListNode* right = middle->next;
        middle->next = nullptr; //detach

        left = sortList(left);
        right = sortList(right);

        return mergeLL(left, right);
                
    }
};

// sort an LL in ascending order
// first intuition is to do it (not in place ig?)
// just maintain an extra array, sort it then overwrite values
// would be O(2n + nlogn) and O(n) space complexity 

// another way is to use merge sort as in divide the linked list into two halves and then 
// merge while ordering them correctly
// this way the space complexity is maintained to O(1)
