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

        ListNode* curr = head;
        int counter = 1;
        queue<int> odd;
        queue<int> even;
        while(curr != nullptr){
            if(counter%2 == 1){
                odd.push(curr->val);
            }
            if(counter%2 == 0){
                even.push(curr->val);
            }
            curr = curr->next;
            counter++;
        }
        
        curr = head;

        while(curr != nullptr){
            if(!odd.empty()){
                curr->val = odd.front();
                odd.pop();
            }
            else{
                curr->val = even.front();
                even.pop();
            }
            curr = curr->next;
        }
        return head;
    }
};

// primary intuition goes that store and chenge values of even and odd respectively