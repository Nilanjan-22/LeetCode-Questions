class Solution {
public:
    bool solve (long long curPos, long long prevPos , long long finalDist, set<long long>& dist, map<pair<long long,long long>,bool>& dp){
        if(curPos==finalDist)return true;
        if(dp.find({curPos,prevPos})!=dp.end())return dp[{curPos,prevPos}];

        long long step = curPos-prevPos;

        bool possible = false;
        if(dist.find(curPos+step)!=dist.end()){
            possible = possible | solve(curPos+step,curPos,finalDist,dist,dp);
        }
        if(dist.find(curPos+step-1LL)!=dist.end() && step!=1){
            possible = possible | solve(curPos+step-1LL,curPos,finalDist,dist,dp);
        }
        if(dist.find(curPos+step+1LL)!=dist.end()){
            possible = possible | solve(curPos+step+1LL,curPos,finalDist,dist,dp);
        }

        return dp[{curPos,prevPos}]=possible;

    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1)return false;
        int n=stones.size();
        set<long long> distance;
        for(int i=2;i<stones.size();i++){
            distance.insert(stones[i]);
        }
        long long finalDist=stones[n-1];
        map<pair<long long,long long> , bool> dp;

        return solve(1,0,finalDist,distance,dp);
    }
};