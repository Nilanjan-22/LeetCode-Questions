class Solution {
public:
    string addBinary(string a, string b) {
        int carry=0;
        string ans="";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int i;
        for(i=0;i<min(a.size(),b.size());i++){
            int sum=(a[i]-48)+(b[i]-48)+carry;
            if(sum==2 || sum==0){
                if(sum==0)carry=0;
                else carry=1;
                ans.push_back('0');
            }
            else{
                if(sum==3)carry=1;
                else carry=0;
                ans.push_back('1');
            }
        }

        while(i<a.size()){
            int sum= (a[i]-48) + carry;
            if(sum==2 || sum==0){
                 if(sum==0)carry=0;
                else carry=1;
                ans.push_back('0');
            }
            else{
                if(sum==3)carry=1;
                else carry=0;
                ans.push_back('1');
            }
            i++;
        }

        while(i<b.size()){
            int sum= (b[i]-48) + carry;
            if(sum==2 || sum==0){
                if(sum==0)carry=0;
                else carry=1;
                ans.push_back('0');
            }
            else{
                if(sum==3)carry=1;
                else carry=0;
                ans.push_back('1');
            }
            i++;
        }

        if(carry!=0){
            ans.push_back('1');
            carry=0;
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};