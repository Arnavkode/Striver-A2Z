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
    ListNode* sortList(ListNode* head) {


        if(head == nullptr) return nullptr;
        vector<int> values;

        ListNode* curr = head;

        while(curr!= nullptr){
            values.push_back(curr->val);
            curr = curr -> next;
        }

        sort(values.begin(), values.end());

        curr = head;
        int n = values.size();

        for(int i =0 ; i< n ;i++){
            curr -> val = values[i];
            curr = curr-> next;
        }

        return head;
        
    }
};

// sort an LL in ascending order
// first intuition is to do it (not in place ig?)
// just maintain an extra array, sort it then overwrite values
// would be O(nlogn) and O(n) space complexity 