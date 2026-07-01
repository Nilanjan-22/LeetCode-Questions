class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int n=a.size(),m=b.size();
        vector<int> lps(1,0);
        string temp = b;
        temp+='#';
        temp+=a;

        int i=1;
        int cnt=1;
        while(true){
            if(temp.size()==i){
                temp+=a;
                cnt++;
            }
            int prevInd=lps[i-1];
            while(prevInd>0 && temp[i]!=temp[prevInd]){
                prevInd=lps[prevInd-1];
            }
            if(temp[i]==temp[prevInd])lps.push_back(prevInd+1);
            else lps.push_back(0);

            if(lps[i]==b.size())break;
            if(i>2*n+m && lps[i]-lps[n+m]!=i-n-m)return -1;
            i++;
        }
        return cnt;
    }
};