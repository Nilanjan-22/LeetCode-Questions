class Solution {
public:
    int numberOfWays(string corridor) {
        long long cnt=0,ans=0,m=1e9+7;
        vector<int> points;
        for(int i=0; i<corridor.size();i++){
            if(corridor[i]=='S'){
                cnt++;
                if(cnt>1)points.push_back(i);
            }
            
        }
        if(points.size()>1)points.pop_back();
        if(cnt%2==1 || cnt==0)return ans;
        else{
            ans=1;
            for(int j=0;j<points.size()-1;){
                long long mul=(points[j+1]-points[j]);
                ans%=m;
                ans*=mul;
                ans%=m;
                j+=2;
            }
            return ans;
        }
    }
};