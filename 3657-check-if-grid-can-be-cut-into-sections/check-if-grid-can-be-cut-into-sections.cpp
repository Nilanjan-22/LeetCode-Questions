class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        int s=rectangles.size();
        vector<pair<int,int>> x(s),y(s);
        for(int i=0;i<s;i++){
            x[i].first=rectangles[i][0];
            x[i].second=rectangles[i][2];
            y[i].first=rectangles[i][1];
            y[i].second=rectangles[i][3];
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());

        //check for x
        int maxi=-1,cuts=0;
        for(int i=0;i<s;i++){
            if(x[i].first>=maxi && maxi!=-1)cuts++;
            maxi=max(x[i].second,maxi);
        }
        if(cuts>1)return true;

        //check for y
        maxi=-1,cuts=0;
        for(int i=0;i<s;i++){
            if(y[i].first>=maxi && maxi!=-1)cuts++;
            maxi=max(y[i].second,maxi);
        }
        if(cuts>1)return true;
        return false;
    }
};