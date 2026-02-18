class Solution {
public:
    vector<int> segtree;

    void update(int i,int l, int r, int idx){
        if(l==r){
            segtree[i]=1;
            return;
        }
        int mid=(l+r)/2;
        if(idx<=mid)update(2*i+1,l,mid,idx);
        else{
            update(2*i+2,mid+1,r,idx);
        }

        segtree[i]=segtree[2*i+1]+segtree[2*i+2];
        return;
    }

    int query(int i, int l, int r, int st, int en){
        if(l>en || r<st)return 0;
        if(l>=st && r<=en)return segtree[i];
        
        int mid=(l+r)/2;
        return query(2*i+1,l,mid,st,en)+query(2*i+2,mid+1,r,st,en);
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long ans=0;
        int n=nums1.size();
        segtree.resize(4*n,0);
        map<int,int> mp;
        for(int i=0;i<nums2.size();i++){
            mp[nums2[i]]=i;
        }

        for(int i=0;i<n;i++){
            int idxAtNums2=mp[nums1[i]];
            long long leftcommon=query(0,0,n-1,0,idxAtNums2);
            long long leftuncommon=i-leftcommon;
            long long rightcommon=n-idxAtNums2-1-leftuncommon;
            ans+=leftcommon*rightcommon;
            update(0,0,n-1,idxAtNums2);
        }
        return ans;
    }
};