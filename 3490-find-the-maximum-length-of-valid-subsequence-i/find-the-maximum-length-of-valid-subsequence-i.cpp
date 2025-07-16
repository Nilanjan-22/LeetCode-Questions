class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int odd=0,eve=0,oe=0,eo=0;
        bool oeeve=false, eoeve=true;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                eve++;
                if(eoeve){
                    eo++;
                    eoeve=false;
                }
                if(oeeve){
                    oe++;
                    oeeve=false;
                }
            }
            else{
                odd++;
                if(!eoeve){
                    eo++;
                    eoeve=true;
                }
                if(!oeeve){
                    oe++;
                    oeeve=true;
                }
            }
        }
        return max(odd,max(eve,max(oe,eo)));
    }
};