class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int maxVal=-1;
        for(int i=0;i<nums.size();i++){
            maxVal=max(maxVal,nums[i]);
        }
    

        vector<long long> factorFreq(maxVal+1,0);

        for(int i=0;i<nums.size();i++){
            for(int j=1;j*j<=nums[i];j++){
                if(nums[i]%j==0){
                    factorFreq[j]++;
                    if(nums[i]/j !=j){
                        factorFreq[nums[i]/j]++;
                    }
                }
            }
        }
        // for(int i=0;i<=maxVal;i++){
        //     cout<<factorFreq[i]<<" ";
        // }
        // cout<<endl;

        vector<long long> GCDPairCount(maxVal+1,0);
        for(int i=maxVal;i>=1;i--){
            if(factorFreq[i]<2)continue;
            GCDPairCount[i] = (factorFreq[i]*(factorFreq[i]-1))/2LL;

            for(int factor = 2*i ; factor<=maxVal ; factor+=i){
                GCDPairCount[i]-=GCDPairCount[factor];
            }
        }

        set<pair<int,int>> sortedGCDPrefix;
        long long sum=0;
        for(int i=1;i<=maxVal;i++){
            if(GCDPairCount[i]==0)continue;
            sum+=GCDPairCount[i];
            sortedGCDPrefix.insert({sum,i});
        }

        // for(auto it: sortedGCDPrefix){
        //     cout<<it.second <<" : "<<it.first<<endl;
        // }
        vector<int> ans(queries.size());

        for(int i=0;i<queries.size();i++){
            long long idx = queries[i];
            auto it = sortedGCDPrefix.lower_bound({idx+1,0});
            ans[i]=it->second;
        }
        return ans;
    }
};