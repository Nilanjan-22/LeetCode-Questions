class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int> freq1,freq2;
        int n=s1.size();
        for(int i=0;i<n;i+=2){
            freq1[s1[i]]++;
            freq1[s2[i]]--;
        }
        for(int i=1;i<n;i+=2){
            freq2[s1[i]]++;
            freq2[s2[i]]--;
        }

        for(auto it: freq1){
            if(it.second!=0)return false;
        }

        for(auto it: freq2){
            if(it.second!=0)return false;
        }
        
        return true;
    }
};