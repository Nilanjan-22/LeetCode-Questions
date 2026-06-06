class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int majority1=-1,majority2=-1;
        int n=nums.size();

        for(int i=0;i<n;i++){
            if(cnt1==0 && majority2!=nums[i]){
                majority1=nums[i];
                cnt1++;
            }
            else if(cnt2==0 && majority1!=nums[i]){
                majority2=nums[i];
                cnt2++;
            }

            else if(nums[i]==majority1)cnt1++;
            else if(nums[i]==majority2)cnt2++;
            else {
                cnt1--;
                cnt2--;
            }

        }

        int occ1=0,occ2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==majority1)occ1++;
            else if(nums[i]==majority2)occ2++;
        }

        vector<int> ans;
        if(occ1>n/3)ans.push_back(majority1);
        if(occ2>n/3)ans.push_back(majority2);

        return ans;
    }
};