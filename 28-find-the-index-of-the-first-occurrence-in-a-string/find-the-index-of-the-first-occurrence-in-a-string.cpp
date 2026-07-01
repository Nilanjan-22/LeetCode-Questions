class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size(),m=needle.size();
        if(m>n)return -1;
        vector<int> lps(n+m+1,0);

        string temp=needle;
        temp.push_back('#');
        temp+=haystack;

        for(int i=1;i<n+m+1;i++){
            int prevInd=lps[i-1];
            while(prevInd>0 && temp[i]!=temp[prevInd]){
                prevInd=lps[prevInd-1];
            }
            if(temp[i]==temp[prevInd])lps[i]=prevInd+1;
            else prevInd=0;
        }

        for(int i=0;i<n+m+1;i++){
            if(lps[i]==needle.size())return i-2*needle.size();
        }
        return -1;
    }
};