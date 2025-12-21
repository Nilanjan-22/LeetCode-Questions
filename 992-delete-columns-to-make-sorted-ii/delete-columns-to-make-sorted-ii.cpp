class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int del=0;
        vector<bool> sorted(strs.size()-1,false);

        for(int c=0; c<strs[0].size(); c++){
            bool deleted=false;

            for(int r=0; r<strs.size()-1; r++){
                if(!sorted[r] && strs[r][c]>strs[r+1][c]){
                    del++;
                    deleted=true;
                    break;
                }
            }

            if(!deleted){
                for(int i=0;i<strs.size()-1;i++){
                    sorted[i] = sorted[i]|(strs[i][c]<strs[i+1][c]);
                }
            }

        }
        return del;
    }
};