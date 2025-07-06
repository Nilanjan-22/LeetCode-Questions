class FindSumPairs {
public:
    map<int,int> mp1;
    map<int,int> mp2;
    vector<int> nums2c;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int i=0;i<nums1.size();i++)mp1[nums1[i]]++;
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]]++;
            nums2c.push_back(nums2[i]);
        }
    }
    
    void add(int index, int val) {
        mp2[nums2c[index]]--;
        nums2c[index]+=val;
        mp2[nums2c[index]]++;
    }
    
    int count(int tot) {
        int ans=0;
        for(auto it: mp1){
            int dif=tot-it.first;
            if(it.first>=tot)break;
            else if(mp2.find(dif)!=mp2.end())ans+=it.second*mp2[dif];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */