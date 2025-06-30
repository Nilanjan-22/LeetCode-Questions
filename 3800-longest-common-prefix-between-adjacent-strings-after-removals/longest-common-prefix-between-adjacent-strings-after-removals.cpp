class Solution {
public:
    vector<int> build(vector<pair<int,int>>& v){
        int n=v.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++){
            vec[i].first=v[i].first;
            vec[i].second=i;
        }

        sort(vec.rbegin(), vec.rend());

        vector<int> final(n);
        for(int i=0;i<n;i++){
            final[i]=vec[i].second;
        }
        return final;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n=words.size();
        vector<pair<int,int>> max_l(n,{0,0});
        if(n==1)return {0};

        for(int i=0;i<n;i++){
            if(i+1<n){
                int cnt1=0;
                while(cnt1<min(words[i].size(), words[i+1].size()) && words[i][cnt1]==words[i+1][cnt1]){
                    cnt1++;
                }
                max_l[i].first=cnt1;
            }
            if(i+2<n){
                int cnt1=0;
                while(cnt1<min(words[i].size(), words[i+2].size()) && words[i][cnt1]==words[i+2][cnt1]){
                    cnt1++;
                }
                max_l[i].second=cnt1;
            }
        }

        vector<int> max_index;
        max_index=build(max_l);

        vector<int> ans(n);

        for(int i=0;i<n;i++){
            if(i==0){
                if(max_index[0]==0){
                    ans[i]=max_l[max_index[1]].first;
                }
                else {
                    ans[i]=max_l[max_index[0]].first;
                }
            }
            else if(i==n-1){
                if(max_index[0]==n-1)ans[n-1]=0;
                else if(max_index[0]==n-2){
                    ans[n-1]=max(max_l[max_index[1]].first, max_l[n-2].second);
                }
                else{
                    ans[n-1]=max(max_l[max_index[0]].first, max_l[n-2].second);
                }
            }
            else{
                int ind=0;
                while(ind<n && (max_index[ind]==i-1||max_index[ind]==i)){
                    ind++;
                }
                if(ind<n){
                    ans[i]=max(max_l[max_index[ind]].first,max_l[i-1].second);
                }
                else{
                    ans[i]=max_l[i-1].second;
                }
            }
        }
        return ans;
    }
};