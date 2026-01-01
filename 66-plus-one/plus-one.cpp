class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int ls=digits.size();
        for(int i=0;i<digits.size();i++){
            if(ls==digits.size() && digits[i]==9)ls=i;
            else if(digits[i]!=9)ls=digits.size();
        }
        if(ls==0){
            ans.push_back(1);
            for(int i=0;i<digits.size();i++)ans.push_back(0);
        }
        else{
            for(int i=0;i<ls-1;i++){
                ans.push_back(digits[i]);
            }
            ans.push_back(digits[ls-1]+1);
            for(int i=ls;i<digits.size();i++)ans.push_back(0);
        }

        return ans;
    }
};