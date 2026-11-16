class Solution {
public:
    string digitSum(string s, int k) {
        string ans=s;
        while(ans.size()>k){
            string temp=ans;
            ans="";
            int i=0;
            while(i<temp.size()){
                int sum=0;
                for(int it=0;it<min(k,(int)temp.size()-i);it++){
                    sum+=temp[it+i]-'0';
                }
                ans+=to_string(sum);
                i+=k;
            }
        }
        return ans;
    }
};