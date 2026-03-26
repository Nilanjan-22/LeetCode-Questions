class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum=0;
        int n=grid.size(),m=grid[0].size();

        unordered_map<long long,int> freq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                freq[grid[i][j]]++;
                sum+=(long long)grid[i][j];
            }
        }

        unordered_map<long long,int> temp=freq;
        long long sum1=0;
        //trying horizontal cut
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum1+=(long long)grid[i][j];
                temp[grid[i][j]]--;
                
                if(j==m-1){
                    long long dif=abs(2*sum1 - sum);
                    if(dif==0)return true;
                    if(2*sum1>sum){
                        if(freq.find(dif)!=freq.end() && temp[dif]!=freq[dif]){
                            if(i==0 && grid[0][0]!=dif && grid[0][m-1]!=dif)continue;
                            if(j==0 && grid[0][0]!=dif && grid[i][0]!=dif)continue;
                            else return true;
                        }
                    }
                    else{
                        if(freq.find(dif)!=freq.end() && temp[dif]>0){
                            if(i==n-2 && grid[n-1][0]!=dif && grid[n-1][m-1]!=dif)continue;
                            if(j==0 && grid[i+1][0]!=dif && grid[n-1][0]!=dif)continue;
                            else return true;
                        }
                    }
                }
            }
        }

        //trying vertical cut
        sum1=0;
        temp=freq;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                sum1+=(long long)grid[i][j];
                temp[grid[i][j]]--;
                
                if(i==n-1){
                    long long dif=abs(2*sum1 - sum);
                    if(dif==0)return true;
                    if(2*sum1>sum){
                        if(freq.find(dif)!=freq.end() && temp[dif]!=freq[dif]){
                            if(j==0 && grid[0][0]!=dif && grid[n-1][0]!=dif)continue;
                            if(i==0 && grid[0][j]!=dif && grid[0][0]!=dif)continue;
                            else return true;
                        }
                    }
                    else{
                        if(freq.find(dif)!=freq.end() && temp[dif]>0){
                            if(j==m-2 && grid[0][m-1]!=dif && grid[n-1][m-1]!=dif)continue;
                            if(i==0 && grid[0][j+1]!=dif && grid[0][m-1]!=dif)continue;
                            else return true;
                        }
                    }
                }
            }
        }

        //not possible
        return false;
    }
};