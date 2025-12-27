class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0,maxi=0;

        map<char,int> mp;

        int l=0,r=0;
        while(r<s.size()){
            mp[s[r]]++;

            if(mp.size()==r-l+1){
                ans=max(ans,r-l+1);
                r++;
            }
            else{
                if(mp[s[l]]==1)mp.erase(s[l]);
                else mp[s[l]]--;

                l++;
                r++;
            }
        }
        return ans;

    }
};