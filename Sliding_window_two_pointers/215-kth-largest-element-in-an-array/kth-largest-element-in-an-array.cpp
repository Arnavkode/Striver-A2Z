class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int> pq; //max heap implementation
        for(int n : nums) pq.push(n);

        for(int n = 0; n < k-1 ; n++){
            pq.pop();
        }

        return pq.top();
        
    }
};

// need to find the kth largest element of this array