class Solution {
public:
    bool consecutiveSetBits(int n) {
        int temp=n;
        int maxCnt=0;
        int pairCnt=0;
        int cnt=0;
        while(temp>0){
            if(temp%2==0){
                cnt=0;
            }
            else{
                cnt++;
                if(cnt==2)pairCnt++;
                maxCnt=max(maxCnt,cnt);
            }
            temp/=2;
        }
        if(maxCnt==2 && pairCnt==1)return true;
        return false;
    }
};