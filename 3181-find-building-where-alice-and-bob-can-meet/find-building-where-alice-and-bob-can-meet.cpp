// class Solution {
// public:
//     vector<int> segtree;
//     void build(int i, int l, int r, vector<int> heights){
//         if(l==r){
//             segtree[i]=heights[l];
//             return;
//         }
//         int mid=(l+r)/2;
//         build(2*i+1,l,mid,heights);
//         build(2*i+2,mid+1,r,heights);
//         segtree[i]=max(segtree[2*i+1],segtree[2*i+2]);
//         return;
//     }

//     int query(int i, int l, int r, int st, int en){
//         if(st<=l && r<=en)return segtree[i];
//         if(st>r || en<l)return -1;
//         int mid=(l+r)/2;
//         return max(query(2*i+1,l,mid,st,en),query(2*i+2,mid+1,r,st,en));
//     }

//     vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
//         int n=heights.size();
//         segtree.resize(4*n);
//         build(0,0,n-1,heights);

//         int q=queries.size();
//         vector<int> ans(q);
//         for(int i=0;i<q;i++){
//             int s=min(queries[i][0],queries[i][1]),b=max(queries[i][0],queries[i][1]);
//             if(s==b || heights[b]>heights[s]){
//                 ans[i]=b;
//                 continue;
//             }
//             ans[i]=-1;
//             int low=b+1;
//             int high=n-1;

//             while(low<=high){
//                 int mid=(low+high)/2;
//                 if(query(0,0,n-1,low,mid)>max(heights[queries[i][1]],heights[queries[i][0]])){
//                     high=mid-1;
//                     ans[i]=mid;
//                 }
//                 else{
//                     low=mid+1;
//                 }
//             }
//         }
//         return ans;
//     }
// };

class SGTree
{
  vector<int> seg;

public:
  SGTree(int n)
  {
    seg.resize(4 * n + 1, 0);
  }

  void build(int idx, int low, int high, vector<int> &arr)
  {
    if (low == high)
    {
      seg[idx] = arr[low];
      return;
    }

    int mid = low + ((high - low) / 2);
    build(2 * idx + 1, low, mid, arr);
    build(2 * idx + 2, mid + 1, high, arr);
    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
  }

  int query(int idx, int low, int high, int l, int r)
  {

    // no overlap
    if (high < l || low > r)
    {
      return -1;
    }

    // complete overlap
    if (low >= l && high <= r)
    {
      return seg[idx];
    }

    // partial overlap
    int mid = low + ((high - low) / 2);
    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, high, l, r);
    return max(left, right);
  }
};


class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& queries) {
        int q=queries.size();
        int n=h.size();
        SGTree seg(n);
        seg.build(0,0,n-1,h);
        vector<int> ans;
        for(int i=0 ; i<q ; i++){
            int h1=queries[i][0];
            int h2=queries[i][1];
            if(h1==h2 || h[max(h1,h2)]>h[min(h1,h2)]){
                ans.push_back(max(h1,h2));
            }
            else{
                int maxheight=max(h[h1],h[h2]);
                int l=max(h1,h2)+1;
                int r=n-1;
                int curr=-1;
                while(l<=r){
                    int mid=(l+r)/2;
                    int mx=seg.query(0,0,n-1,l,mid);
                    if(mx>maxheight){
                        curr=mid;
                        r=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
                ans.push_back(curr);
            }
        }
        return ans;
    }
};