class Solution {
public:
    int totalWaviness(int num1, int num2) {
        vector<int> temp;
        int waviness=0;
        for(int i=num1; i<=num2;i++){
            int t=i;
            while(t>0){
                temp.push_back(t%10);
                t/=10;
            }
            for(int it=1;it<temp.size()-1;it++){
                if(temp[it]>temp[it-1]&&temp[it]>temp[it+1])waviness++;
                else if(temp[it]<temp[it-1]&&temp[it]<temp[it+1])waviness++;
            }
            temp.clear();
        }

        return waviness;
    }
};