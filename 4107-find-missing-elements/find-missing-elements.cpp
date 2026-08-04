class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> missingElements;

        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mini=nums[0], maxi=nums[n-1];

        int num=mini+1, it=0;
        while(num<maxi){
            if(nums[it]<=num){
                if(nums[it]==num)num++;
                it++;
                continue;
            }

            missingElements.push_back(num);
            num++;

        }


        return missingElements;
    }
};