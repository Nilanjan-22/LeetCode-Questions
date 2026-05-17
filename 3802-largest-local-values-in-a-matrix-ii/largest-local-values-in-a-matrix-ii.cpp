class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<pair<int,int>>> hash(201);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=matrix[i][j];
                hash[val].push_back({i,j});
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int val=matrix[i][j];
                if(val==0)continue;

                bool possible=true;

                for(int it=val+1;it<=200;it++){
                    for(auto it1 : hash[it]){
                        if(abs(it1.first-i)==val && abs(it1.second-j)==val)continue;
                        else if(abs(it1.first-i)<=val && abs(it1.second-j)<=val){
                            possible=false;
                            break;
                        }
                    }
                    if(!possible)break;
                }
                if(possible)count++;
            }
        }

        return count;


    }
};