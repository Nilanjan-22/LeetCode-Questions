class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0)return -1;
        int ans=1, rem=1%k, i=k;
        while(i && rem!=0){
            rem=(rem*10 + 1)%k;
            ans++;
            i--;
        }
        if(rem==0)return ans;
        return -1;
    }
};