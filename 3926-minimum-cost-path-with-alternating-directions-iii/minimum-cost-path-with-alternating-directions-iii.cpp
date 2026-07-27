class Solution {
public:
    vector<pair<int,int>> leftUp = {{-1,0},{0,-1}};
    vector<pair<int,int>> downRight = {{1,0},{0,1}};
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        priority_queue <vector<long long> , vector<vector<long long>> , greater<vector<long long>>> pq;

        vector<vector<vector<long long>>> cost(m,vector<vector<long long>>(n,vector<long long>(2,LLONG_MAX)));
        //cost, movement, i, j
        pq.push({1,1,0,0});
        cost[0][0][1]=1;

        while(!pq.empty()){
            vector<long long> temp = pq.top();
            pq.pop();
            long long price = temp[0], action =temp[1], i=temp[2], j=temp[3];
            if(i==m-1 && j==n-1)return price;
            //wait
            if(cost[i][j][!action]>price+(long long)penalty[i][j]){
                pq.push({price+penalty[i][j],!action,i,j});
                cost[i][j][!action]=price+ (long long)penalty[i][j];
            }

            if(action==1){
                for(auto it: downRight){
                    int ni=i+it.first, nj=j+it.second;
                    if(ni>=0 && nj>=0 && ni<m && nj<n && cost[ni][nj][!action]>price+(ni+1)*(nj+1)){
                        pq.push({price+(ni+1)*(nj+1) ,!action , ni, nj});
                        cost[ni][nj][!action] = price+(ni+1)*(nj+1);
                    }
                }

                for(auto it: leftUp){
                    int ni=i+it.first, nj=j+it.second;
                    if(ni>=0 && nj>=0 && ni<m && nj<n && cost[ni][nj][!action]>price+(ni+1)*(nj+1)+(long long)penalty[i][j]){
                        pq.push({price+(ni+1)*(nj+1)+(long long)penalty[i][j] ,!action , ni, nj});
                        cost[ni][nj][!action] = price+(ni+1)*(nj+1)+(long long)penalty[i][j];
                    }
                }
            }
            else{
                for(auto it: leftUp){
                    int ni=i+it.first, nj=j+it.second;
                    if(ni>=0 && nj>=0 && ni<m && nj<n && cost[ni][nj][!action]>price+(ni+1)*(nj+1)){
                        pq.push({price+(ni+1)*(nj+1) ,!action , ni, nj});
                        cost[ni][nj][!action] = price+(ni+1)*(nj+1);
                    }
                }

                for(auto it: downRight){
                    int ni=i+it.first, nj=j+it.second;
                    if(ni>=0 && nj>=0 && ni<m && nj<n && cost[ni][nj][!action]>price+(ni+1)*(nj+1)+(long long)penalty[i][j]){
                        pq.push({price+(ni+1)*(nj+1)+(long long)penalty[i][j] ,!action , ni, nj});
                        cost[ni][nj][!action] = price+(ni+1)*(nj+1)+(long long)penalty[i][j];
                    }
                }
            }
        }
        return LLONG_MAX;
    }
};