class Solution {
public:
    int cntbits(int x){
        int ans=0;
        while(x>0){
            if(x%2==1)ans++;
            x/=2;
        }
        return ans;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> hr={"0","1","2","3","4","5","6","7","8","9","10","11"};
        vector<string> min={"00","01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31","32","33","34","35","36","37","38","39","40","41","42","43","44","45","46","47","48","49","50","51","52","53","54","55","56","57","58","59","60"};
        vector<string> ans;
        for(int i=0;i<12;i++){
            for(int j=0;j<60;j++){
                if(cntbits(i)+cntbits(j)==turnedOn){
                    string t= hr[i] + ":" +min[j];
                    ans.push_back(t);
                }
            }
        }

        return ans;
    }
};