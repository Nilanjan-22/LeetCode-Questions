#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ordered_set<pair<long long,long long>> st;

        for(int i=1;i<=dist+1;i++){
            st.insert({nums[i],i});
        }

        long long sum=0;
        for(int i=0;i<k-1;i++){
            auto it=st.find_by_order(i);
            sum+=(*it).first;
        }
        long long mini=sum;
        for(int i=2;i<nums.size()-dist;i++){
            bool change=false;
            int ind=st.order_of_key({nums[i-1],i-1});
            st.erase({nums[i-1],i-1});
            if(ind<k-1){
                sum-=nums[i-1];
                change=true;
            }
            st.insert({nums[i+dist],i+dist});
            if(change){
                auto it1=st.find_by_order(k-2);
                int ind2=st.order_of_key({nums[i+dist],{i+dist}});
                if(ind2<k-1){
                    auto it2=st.find_by_order(ind2);
                    sum+=min((*it1).first,(*it2).first);
                }
                else sum+=(*it1).first;
            }
            if(!change){
                int ind2=st.order_of_key({nums[i+dist],{i+dist}});
                if(ind2<k-1){
                    auto it2=st.find_by_order(ind2);
                    sum+=(*it2).first;
                    auto it1=st.find_by_order(k-1);
                    sum-=min((*it1).first,(long long)nums[i-1]);
                }
            }

            mini=min(mini,sum);
        }
        return mini+nums[0];
    }
};