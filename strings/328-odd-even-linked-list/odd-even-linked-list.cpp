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
    ListNode* oddEvenList(ListNode* head) {

        
       
       if(head == nullptr) return nullptr;
        if(!head->next) return head;

       ListNode* oddHead = head;
       ListNode* evenHead = head->next;
       ListNode* curr = evenHead->next;
       
       
       ListNode* oddTail  = oddHead;
       ListNode * evenTail = evenHead;

        long long counter = 1;

        while(curr != nullptr){
        if(counter %2 == 1){
            oddTail -> next = curr;
            oddTail = oddTail->next;
        }
        else{
            evenTail -> next = curr;
        evenTail = evenTail -> next;
        }
        curr = curr->next;
        counter++;
       }
        evenTail -> next = nullptr;
       oddTail -> next = evenHead;

       return oddHead;
       


       

    }
};

// primary intuition goes that store and chenge indices of even and odd respectively

// but this intuition retarded, kinda
// lets have two heads, one odd and one even
// now traversing the LL, if i find odd, lets connect the oddtail to that and if even then even to that
// at the end lets connect the odd tail to even tail

