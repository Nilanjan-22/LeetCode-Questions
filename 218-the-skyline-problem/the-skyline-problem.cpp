class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int,vector<pair<int,int>>> ends; //end - {height, start}
        set<pair<int,int>> heights; // height,start

        vector<vector<int>> ans;

        int idx=-1;
        for(int i=0;i<buildings.size();i++){
            int st=buildings[i][0],h=buildings[i][2],en=buildings[i][1];

            while(!ends.empty() && (ends.begin())->first<=st){
                vector<pair<int,int>> rem=(ends.begin())->second;
                int end=(ends.begin())->first;
                ends.erase(end);
                for(auto it: rem){
                    heights.erase(it);
                }
                if(end==st)continue;
                int maxi=0;
                if(!heights.empty())maxi=(heights.rbegin())->first;
                if(idx==-1 || ans[idx][1]!=maxi){
                    ans.push_back({end,maxi});
                    idx++;
                }
            }
            heights.insert({h,st});
            ends[en].push_back({h,st});
            int j=i+1;
            while(j<buildings.size() && buildings[j][0]==buildings[j-1][0]){
                int e=buildings[j][1],h1=buildings[j][2];
                heights.insert({h1,st});
                ends[e].push_back({h1,st});
                j++;
            }
            i=j-1;
            int maxi=(heights.rbegin())->first;
            if(idx==-1 || ans[idx][1]!=maxi){
                ans.push_back({st,maxi});
                idx++;
            }
        }
        while(!ends.empty()){
            vector<pair<int,int>> rem=(ends.begin())->second;
            int end=(ends.begin())->first;
            ends.erase(end);
            for(auto it: rem){
                heights.erase(it);
            }
            int maxi=0;
            if(!heights.empty())maxi=(heights.rbegin())->first;
            if(idx==-1 || ans[idx][1]!=maxi){
                ans.push_back({end,maxi});
                idx++;
            }
        }
        return ans;
    }
};