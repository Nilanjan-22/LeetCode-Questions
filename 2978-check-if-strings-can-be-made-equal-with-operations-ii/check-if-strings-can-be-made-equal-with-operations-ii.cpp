class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> freq1(26,0),freq2(26,0);
        int n=s1.size();
        for(int i=0;i<n;i+=2){
            freq1[s1[i]-'a']++;
            freq1[s2[i]-'a']--;
        }
        for(int i=1;i<n;i+=2){
            freq2[s1[i]-'a']++;
            freq2[s2[i]-'a']--;
        }

        for(int i=0;i<26;i++){
            if(freq1[i]!=0 || freq2[i]!=0)return false;
        }
        
        return true;
    }
};