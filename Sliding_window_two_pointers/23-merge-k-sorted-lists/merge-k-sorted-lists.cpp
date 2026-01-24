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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        priority_queue<int, vector<int>, greater<int>> pq;

        for(ListNode* node: lists){

            while(node != nullptr){pq.push(node->val);
            node = node ->next;
            }
        }
        if(!pq.empty()){
        ListNode* head = new ListNode(pq.top());
        pq.pop();
        ListNode* tail = head;

        while(!pq.empty()){
            ListNode* temp = new ListNode(pq.top());
            pq.pop();
            tail -> next = temp;
            tail = tail-> next;
            
        }
        return head;
        }
        return nullptr;
    }
};