#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long prefsum=0;
        ordered_set<pair<long long,int>> st;
        long long ans=0;
        st.insert({0,0});
        int it=1;
        for(int i=0;i<nums.size();i++){
            prefsum+=nums[i];
            ans+=(long long)st.order_of_key({prefsum-lower+1,-1})-(long long)st.order_of_key({prefsum-upper,-1});
            st.insert({prefsum,it++});

        }
        return ans;
    }
};