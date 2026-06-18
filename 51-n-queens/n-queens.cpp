class Solution {
public:
    void placingNQueens(int i,int n,vector<pair<int,int>>& pos, vector<string>& oneSol, vector<vector<string>>& ans){
        if(i>=n){
            ans.push_back(oneSol);
        }
        vector<int> placements;

        if(pos.size()==0){
            for(int it=0;it<n;it++)placements.push_back(it);
        }
        else{
            for(int it=0;it<n;it++){
                bool isPos=true;
                for(auto &val: pos){
                    if(it==val.first || it==val.first-(i-val.second) || it==val.first+(i-val.second)){
                        isPos=false;
                        break;
                    }
                }
                if(isPos)placements.push_back(it);
            }
        }
        string temp(n,'.');
        for(auto it: placements){
            temp[it]='Q';
            oneSol.push_back(temp);
            pos.push_back({it,i});
            placingNQueens(i+1,n,pos,oneSol,ans);
            pos.pop_back();
            oneSol.pop_back();
            temp[it]='.';
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> oneSol;
        vector<pair<int,int>> pos;
        vector<vector<string>> ans;
        placingNQueens(0,n,pos,oneSol,ans);
        return ans;
    }
};