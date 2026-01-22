class Solution {
public:
    bool check_sort(vector<int>& v){
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>v[i+1])return false;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> cur, prev;
        prev=nums;
        while(!check_sort(prev)){
            int adj_sum=1e9, ind=-1;
            for(int i=0;i<prev.size()-1;i++){
                if(prev[i]+prev[i+1]<adj_sum){
                    ind=i;
                    adj_sum=prev[i]+prev[i+1];
                }
            }
            for(int i=0;i<prev.size();i++){
                if(i==ind){
                    cur.push_back(adj_sum);
                    i++;
                }
                else cur.push_back(prev[i]);
            }
            prev=cur;
            cur={};
        }
        return nums.size()-prev.size();
    }
};