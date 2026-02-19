class Solution {
public:
    vector<int> segtree;

    void build(int i, int l, int r, vector<int>& baskets){
        if(l==r){
            segtree[i]=baskets[l];
            return;
        }
        int mid=(l+r)/2;
        build(2*i+1,l,mid,baskets);
        build(2*i+2,mid+1,r,baskets);

        segtree[i]=max(segtree[2*i+1],segtree[2*i+2]);
        return;
    }
    void update(int i, int l, int r, int idx){
        if(l==r){
            segtree[i]=-1;
            return;
        }
        int mid=(l+r)/2;

        if(idx<=mid)update(2*i+1,l,mid,idx);
        else update(2*i+2,mid+1,r,idx);

        segtree[i]= max(segtree[2*i+1],segtree[2*i+2]);
        return;
    }

    int query(int i, int l, int r, int st, int en){
        if(l>en || r<st)return -1;
        if(l>=st && r<=en)return segtree[i];

        int mid=(l+r)/2;
        return max(query(2*i+1,l,mid,st,en), query(2*i+2,mid+1,r,st,en));
    }
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=0;
        int n=baskets.size();
        segtree.resize(4*n);
        build(0,0,n-1,baskets);

        for(int i=0;i<fruits.size();i++){
            if(query(0,0,n-1,0,n-1)<fruits[i]){
                ans++;
                continue;
            }
            else{
                int low=0,high=n-1;
                int chosenIdx;
                while(low<=high){
                    int mid=(low+high)/2;
                    if(query(0,0,n-1,0,mid)>=fruits[i]){
                        high=mid-1;
                        chosenIdx=mid;
                    }
                    else low=mid+1;
                }
                update(0,0,n-1,chosenIdx);
            }
        }
        return ans;
    }
};