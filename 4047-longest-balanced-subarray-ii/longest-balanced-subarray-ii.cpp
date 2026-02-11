class Solution {
public:
    vector<int> segmin;
    vector<int> segmax;
    vector<int> lazy;
    int n;
    void propagate(int i, int l, int r){
        segmin[i]+=lazy[i];
        segmax[i]+=lazy[i];
        if(l!=r){
            lazy[2*i+1]+=lazy[i];
            lazy[2*i+2]+=lazy[i];
        }
        lazy[i]=0;
    }
    void update(int start, int end , int val , int i, int l, int r){
        if(lazy[i]!=0){
            propagate(i,l,r);
        }
        if(l>end || r<start)return;
        else if(l>=start && r<=end){
            lazy[i]=val;
            propagate(i,l,r);
            return;
        }
        else{
            int mid=(l+r)/2;
            update(start,end,val,2*i+1,l,mid);
            update(start,end,val,2*i+2,mid+1,r);
            segmin[i]=min(segmin[2*i+1],segmin[2*i+2]);
            segmax[i]=max(segmax[2*i+1],segmax[2*i+2]);
            return;
        }
    }
    
    int findleftmost0(int i, int l, int r){
        propagate(i,l,r);
        if(segmin[i]>0 || segmax[i]<0)return INT_MAX;

        if(l==r)return l;

        int mid=(l+r)/2;

        // return min(findleftmost0(2*i+1,l,mid),findleftmost0(2*i+2,mid+1,r));
        int left=findleftmost0(2*i+1,l,mid);
        if(left!=INT_MAX)return left;
        return findleftmost0(2*i+2,mid+1,r);
    }

    int longestBalanced(vector<int>& nums) {
        n=nums.size();
        unordered_map<int,int> mp;

        segmax.resize(4*n,0);
        segmin.resize(4*n,0);
        lazy.resize(4*n,0);

        int ans=0;
        for(int i=0;i<n;i++){
            int prev=-1;
            if(mp.count(nums[i]))prev=mp[nums[i]];

            int val;
            if(nums[i]%2==0)val=1;
            else val=-1;

            if(prev!=-1){
                update(0,prev,-val,0,0,n-1);
            }

            update(0,i,val,0,0,n-1);

            int l= findleftmost0(0,0,n-1);
            ans=max(ans,i-l+1);
            mp[nums[i]]=i;
        }
        return ans;
    }
};