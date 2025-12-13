class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string> electronics,grocery,pharmacy,restaurant;

        int n=code.size();
        for(int i=0;i<n;i++){
            if(isActive[i]){
                string s=code[i];
                bool valid=true;
                for(int j=0;j<s.size();j++){
                    if(((int)s[j]>=48 && (int)s[j]<=57) || ((int)s[j]>=65 && (int)s[j]<=90)||((int)s[j]>=97 && (int)s[j]<=122)||(int)s[j]==95)continue;
                    else{
                        valid=false;
                        break;
                    }
                }
                if(s.size()==0)valid=false;
                // cout<<s<<" "<<valid<<" "<<endl;
                if(valid){
                    if(businessLine[i]=="electronics")electronics.push_back(code[i]);
                    else if(businessLine[i]=="grocery")grocery.push_back(code[i]);
                    else if(businessLine[i]=="pharmacy")pharmacy.push_back(code[i]);
                    else if(businessLine[i]=="restaurant")restaurant.push_back(code[i]);
                }
            }
        }
        vector<string> ans;
        sort(electronics.begin(),electronics.end());
        sort(grocery.begin(),grocery.end());
        sort(pharmacy.begin(),pharmacy.end());
        sort(restaurant.begin(),restaurant.end());

        for (string i : electronics) ans.push_back(i);
        for (string i : grocery) ans.push_back(i);
        for (string i : pharmacy) ans.push_back(i);
        for (string i : restaurant) ans.push_back(i);

        return ans;
    }
};