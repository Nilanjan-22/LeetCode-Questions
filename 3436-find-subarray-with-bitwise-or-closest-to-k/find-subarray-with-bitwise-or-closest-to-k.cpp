class Solution {
public:
    vector<int> segtree;

    void build(int i, int l , int r, vector<int>& arr){
        if(l==r){
            segtree[i]=arr[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*i+1,l,mid,arr);
        build(2*i+2,mid+1,r,arr);

        segtree[i]=segtree[2*i+1]|segtree[2*i+2];
        return;
    }

    int query(int i, int l, int r, int st, int en){
        if(l>en || r<st)return 0;
        if(l>=st && r<=en)return segtree[i];

        int mid=(l+r)/2;
        return query(2*i+1,l,mid,st,en)|query(2*i+2,mid+1,r,st,en);
    }
    int minimumDifference(vector<int>& arr, int target) {
        int n=arr.size();
        segtree.resize(4*n);
        build(0,0,n-1,arr);

        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int low=i,high=n-1;
            int temp=query(0,0,n-1,i,high);
            ans=min(ans,abs(temp-target));
            while(low<=high){
                int mid=(low+high)/2;
                int val=query(0,0,n-1,i,mid);
                ans=min(ans,abs(val-target));
                if(val>target)high=mid-1;
                else low=mid+1;
            }
        }
        return ans;
    }
};
