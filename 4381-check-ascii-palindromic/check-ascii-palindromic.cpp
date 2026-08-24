class Solution {
public:
    bool isPalindromic(string s) {
        string binaryS="";
        for(auto it: s){
            int num=(int)it;
            string temp="";
            while(num>0){
                int rem = num%2;
                if(rem==0)temp.push_back('0');
                else temp.push_back('1');
                num/=2;
            }
            temp.push_back('0');
            reverse(temp.begin(),temp.end());
            binaryS+=temp;
        }
        cout<<binaryS;
        int i=0,j=binaryS.size()-1;
        while(i<j){
            if(binaryS[i++]!=binaryS[j--])return false;
        }
        return true;
    }
};