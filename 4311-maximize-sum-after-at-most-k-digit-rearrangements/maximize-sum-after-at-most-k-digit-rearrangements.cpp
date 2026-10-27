class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> changes(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            int num = nums[i];
            string numStr = to_string(num);
            sort(numStr.rbegin(),numStr.rend());
            int maxPerm = stoi(numStr);
            changes[i]=maxPerm-num;
            sum+=num;
        }

        sort(changes.rbegin(),changes.rend());

        for(int i=0;i<k;i++){
            sum+=changes[i];
        }
        return sum;
    }
};