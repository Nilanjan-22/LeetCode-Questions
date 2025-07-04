class Solution {
public:
    bool pos(string& s, string& p, vector<int>& removable, int k){
        if(k==0)return true;

        string c=s;
        for(int i=0;i<k;i++){
            c[removable[i]]='*';
        }
        int i=0,j=0;
        while(i<c.size() && j<p.size()){
            if(c[i]==p[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        if(j==p.size())return true;
        return false;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        // use binary search
        int n=s.size(),m=p.size(),r=removable.size();
        int low=0,high=r;
        int ans=0;

        while(low<=high){
            int mid=(low+high)/2;
            if(pos(s,p,removable,mid)){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }

        return ans;
    }
};