class Solution {
public:
    int checkLength(int num){
        int cnt=0;
        while(num>0){
            cnt++;
            num/=10;
        }
        return cnt;
    }
    int startingNum(int dig){
        int startNum=0;
        for(int i=0;i<dig;i++){
            startNum*=10;
            startNum+=i+1;
        }
        return startNum;
    }
    vector<int> sequentialDigits(int low, int high) {
        int stDigits=checkLength(low);
        int startNum=0;
        int addIt=0;
        for(int i=0;i<stDigits;i++){
            startNum*=10;
            startNum+=i+1;

            addIt*=10;
            addIt+=1;
        }
        vector<int> ans;
        int prevLen=stDigits;
        int lastDig=startNum%10;
        while(startNum<=high){
            int len=checkLength(startNum);
            if(len>prevLen){
                startNum = startingNum(len);
                prevLen=len;
                addIt*=10;
                addIt+=1;
                lastDig=startNum%10;
            }
            
            if(startNum>=low && startNum<=high && startNum%10 == lastDig)ans.push_back(startNum);
            lastDig++;
            startNum+=addIt;
        }
        return ans;
    }
};