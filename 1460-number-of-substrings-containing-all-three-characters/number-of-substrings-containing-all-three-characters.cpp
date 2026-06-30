class Solution {
public:
    bool checkPossible(int i, int j, vector<vector<int>>& countOfChars){
        if(i==0){
            for(int it=0;it<3;it++){
                if(countOfChars[j][it]==0)return false;
            }
        }
        else{
            for(int it=0;it<3;it++){
                if(countOfChars[j][it]-countOfChars[i-1][it]==0)return false;
            }
        }
        return true;
    }
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> countOfChars(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            if(i>0){
                countOfChars[i]=countOfChars[i-1];
            }
            countOfChars[i][s[i]-'a']++;
        }

        int noOfSubstrings=0;

        for(int i=0;i<n;i++){
            int low=i,high=n-1;
            int maxNo=0;
            while(low<=high){
                int mid=(low+high)/2;
                if(checkPossible(i,mid,countOfChars)){
                    maxNo=max(maxNo,n-mid);
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            noOfSubstrings+=maxNo;
        }

        return noOfSubstrings;

    }
};