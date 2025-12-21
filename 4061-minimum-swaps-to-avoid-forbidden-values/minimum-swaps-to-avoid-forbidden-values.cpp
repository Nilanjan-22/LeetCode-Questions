class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        map<int,int> unmatched;
        int tum=0, mme=-1, maxm=0;
        map<int,int>matchedfreq;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==forbidden[i]){
                matchedfreq[nums[i]]++;
                if(maxm<matchedfreq[nums[i]])mme=nums[i];
                maxm=max(maxm, matchedfreq[nums[i]]);
                
            }
            else {
                unmatched[nums[i]]++;
                unmatched[forbidden[i]]++;
                tum++;
            }
        }
       
        bool pos=false;
        int m= nums.size()-tum;
        int need=2*maxm-m;
        if(maxm<=m/2)mme=-1;
        if(mme==-1 && m%2==0)pos=true;
        else if(mme==-1){
            for(auto it: matchedfreq){
                if(tum-unmatched[it.first]>0){
                    pos=true;
                    break;
                }
            }
        }
        else{
            if(tum-unmatched[mme]>=need)pos=true;
        }

        if(maxm==1 && m>1)pos=true;
        
        if(pos && need>0)return (m-need)/2 + need;
        else if(pos) return (m+1)/2;
        return -1;





    }
};