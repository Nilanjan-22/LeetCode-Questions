class Solution {
public:
    int maxLenHavingNum(int num, map<int,int>& hashMap){
        if(num==1)return hashMap[1]%2==0 ? hashMap[1]-1 : hashMap[1];
        int cnt=1;
        int temp=num;
        while(1){
            int newTemp=sqrt(temp);
            if((double)newTemp!=sqrt(temp) || hashMap[newTemp]<2)break; 
            cnt+=2;
            temp=newTemp;
        }
        return cnt;
    }
    int maximumLength(vector<int>& nums) {
        map<int,int> hashMap;
        int n=nums.size();
        for(int i=0;i<n;i++){
            hashMap[nums[i]]++;
        }
        int maxLen=1;
        for(auto it: hashMap){
            int num=it.first;
            maxLen=max(maxLen,maxLenHavingNum(num,hashMap));
        }
        return maxLen;
    }
};