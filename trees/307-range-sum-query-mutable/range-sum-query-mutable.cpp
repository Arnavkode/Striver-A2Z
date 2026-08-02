class NumArray {
public:

    vector<int> tree;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        tree.resize(n+1);

        for(int i = 1; i < tree.size() ; i++){
            tree[i] = nums[i-1]; 
        }

        for(int i = 1; i < tree.size() ; i++){
            int parent = i + (i & (-i));
            if(parent < tree.size()){tree[parent] += tree[i];}
        }
    }
    
    void update(int index, int val) {
        int old = sumRange(index, index);
        for(int i = index + 1; i < tree.size() ; i += (i & (-i))){
            tree[i] = tree[i] - old + val;
        }
    }
    
    int sumRange(int left, int right) {
        int leftsum  =0 ;

        for(int i = left; i >0 ; i -= (i & (-i))){
            leftsum += tree[i];
        }

        int rightsum = 0;
        for(int i = right+1; i >0 ; i -= (i & (-i))){
            rightsum += tree[i];
        }

        return rightsum - leftsum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */