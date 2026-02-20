#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_set<int> st;
        int n=nums.size();
        vector<int> ans(n,0);
        st.insert(nums[n-1]);
        for(int i=n-2;i>=0;i--){
            ans[i]=st.order_of_key(nums[i]);
            st.insert(nums[i]);
        }
        return ans;
    }
};