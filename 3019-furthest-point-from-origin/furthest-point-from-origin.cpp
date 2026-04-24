class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int totalSteps=moves.size();
        int leftCnt=0,rightCnt=0;

        for(int i=0;i<totalSteps;i++){
            if(moves[i]=='L')leftCnt++;
            else if(moves[i]=='R')rightCnt++;
        }
        int unknown=totalSteps-leftCnt-rightCnt;
        return abs(leftCnt-rightCnt)+unknown;
    }
};