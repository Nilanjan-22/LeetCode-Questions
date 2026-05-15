class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> separatedVector;
        for(int i=nums.size()-1;i>=0;i--){
            int temp=nums[i];
            while(temp){
                separatedVector.push_back(temp%10);
                temp/=10;
            }
        }
        reverse(separatedVector.begin(),separatedVector.end());
        return separatedVector;
    }
};