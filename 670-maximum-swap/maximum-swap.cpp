class Solution {
public:
    int maximumSwap(int num) {
        int maxi=0,mini=9,pos1=0,t=0,pos2=0;
        vector<int> v;
        int temp=num;
        int i=0;
        while(temp>0){
            if(maxi<temp%10){
                maxi=temp%10;
                mini=maxi;
                t=i;
            }
            else if(mini>temp%10){
                pos1=t;
                pos2=i;
            }
            v.push_back(temp%10);
            temp/=10;
            i++;
        }
        cout<<pos1<<" "<<pos2;
        swap(v[pos1],v[pos2]);
        // reverse(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans+=v[i]*pow(10,i);
        }
        return ans;
    }
};