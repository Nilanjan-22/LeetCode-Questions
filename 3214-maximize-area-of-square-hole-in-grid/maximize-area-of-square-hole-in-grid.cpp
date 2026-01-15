class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int hcons=1,vcons=1;
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        int temp=1;
        for(int i=0;i<hBars.size()-1;i++){
            if(hBars[i+1]-hBars[i]==1){
                temp++;
                hcons=max(temp,hcons);
            }
            else temp=1;

        }
        temp=1;
        for(int i=0;i<vBars.size()-1;i++){
            if(vBars[i+1]-vBars[i]==1){
                temp++;
                vcons=max(temp,vcons);
            }
            else temp=1;
        }
        cout<<vcons<<" "<<hcons;
        return pow(min(vcons,hcons)+1,2);

    }
};