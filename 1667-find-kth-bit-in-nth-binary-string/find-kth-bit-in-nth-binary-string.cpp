class Solution {
public:
    char findKthBit(int n, int k) {
        string s="0";
        for(int i=1;i<=n;i++){
            string temp=s;
            for(int it=0;it<temp.size();it++){
                if(temp[it]=='1')temp[it]='0';
                else temp[it]='1';
            }
            reverse(temp.begin(),temp.end());
            s=s+'1'+temp;
        }
        return s[k-1];
    }
};