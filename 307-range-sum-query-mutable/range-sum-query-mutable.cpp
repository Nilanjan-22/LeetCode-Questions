class NumArray {
public:
    vector<int> segTree;
    int n;
    void BuildTree(int i, int l, int r, vector<int>& nums){
        if(l==r){
            segTree[i]=nums[l];
            return;
        }
        int mid=(l+r)/2;
        BuildTree(2*i+1,l,mid,nums);
        BuildTree(2*i+2,mid+1,r,nums);
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
        return;
    }

    void Update(int i, int l, int r, int ind, int val){
        //if(l>ind || r<ind)return;
        if(l==r){
            segTree[i]=val;
            return;
        }
        int mid=(l+r)/2;
        if(ind<=mid)Update(2*i+1,l,mid,ind,val);
        else Update(2*i+2,mid+1,r,ind,val);
        segTree[i]=segTree[2*i+1]+segTree[2*i+2];
        return;

    }

    int query(int i, int l, int r, int st, int en){
        if(l>en || r<st )return 0;
        else if(l>=st && r<=en)return segTree[i];
        else{
            int mid=(l+r)/2;
            return query(2*i+1,l,mid,st,en)+query(2*i+2,mid+1,r,st,en);
        }
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        segTree.resize(4*n);
        BuildTree(0,0,n-1,nums);
    }
    void update(int index, int val) {
        Update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return query(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */