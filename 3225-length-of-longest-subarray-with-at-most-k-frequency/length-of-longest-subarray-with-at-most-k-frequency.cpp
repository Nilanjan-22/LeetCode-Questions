class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int st=0, en=0;
        map<int, set<int>> hashMap;
        map<int,int> freq;
        int maxSubarrayLen=-1;
        while(en<nums.size()){
            int prevFreq = 0;
            if(freq.find(nums[en])!=freq.end()){
                prevFreq = freq[nums[en]];   
                hashMap[prevFreq].erase(nums[en]);
            }
            if(hashMap[prevFreq].empty())hashMap.erase(prevFreq);

            freq[nums[en]]++;
            hashMap[prevFreq+1].insert(nums[en]);

            int maxFreq = hashMap.rbegin()->first;
            if(maxFreq<=k){
                maxSubarrayLen = max(maxSubarrayLen, en-st+1);
                en++;
            }
            else{
                while(maxFreq>k){
                    int curFreq = freq[nums[st]];
                    if(freq[nums[st]]==1){
                        freq.erase(nums[st]);
                    }
                    else freq[nums[st]]--;
                
                    if(hashMap[curFreq].size()==1)hashMap.erase(curFreq);
                    else hashMap[curFreq].erase(nums[st]);

                    if(curFreq!=1){
                        hashMap[curFreq-1].insert(nums[st]);
                    }
                    st++;
                    maxFreq=hashMap.rbegin()->first;;
                }
                en++;
            }
        }
        return maxSubarrayLen;
    }
};