class Solution {
public:
    bool hasSameDigits(string s) {
        string prev=s;

        while(prev.size()>2){
            string cur="";
            for(int i=1;i<prev.size();i++){
                int sum=prev[i]-'0'+prev[i-1]-'0';
                sum%=10;
                cur.push_back(sum+'0');
            }
            prev=cur;
        }
        return prev[0]==prev[1];
        
    }
};