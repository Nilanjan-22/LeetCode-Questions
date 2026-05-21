class Solution {
public:
    string integerToString(int n){
        string s="";
        while(n>0){
            s.push_back(n%10 + 48);
            n/=10;
        }   
        reverse(s.begin(),s.end());
        return s;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> prefixString;
        string s;
        for(int i=0;i<arr1.size();i++){
            s=integerToString(arr1[i]);
            while(s.size()>0){
                prefixString.insert(s);
                s.pop_back();
            }
        }
        // for(auto it: prefixString){
        //     cout<<it<<endl;
        // }
        int longestCommonPref=0;
        for(int i=0;i<arr2.size();i++){
            s=integerToString(arr2[i]);
            while(s.size()>0){
                if(prefixString.find(s)!=prefixString.end()){
                    longestCommonPref=max(longestCommonPref,(int)s.size());
                    break;
                }
                s.pop_back();
            }
        }

        return longestCommonPref;
    }
};