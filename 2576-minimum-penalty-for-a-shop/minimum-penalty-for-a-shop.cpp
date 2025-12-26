class Solution {
public:
    int bestClosingTime(string customers) {
        int cnt=0,maxcnt=-1,ans=0;

        for(int i=0;i<customers.size();i++){
            if(customers[i]=='Y')cnt++;
            else cnt--;
            if(maxcnt<cnt){
                if(cnt>0)ans=i+1;
                maxcnt=cnt;
            }
        }
        return ans;
    }
};