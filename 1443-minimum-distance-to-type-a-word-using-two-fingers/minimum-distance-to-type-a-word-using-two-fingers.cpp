class Solution {
public:
    map<char,vector<int>> coordinates;
    map<vector<int>,int> dp;
    int size;
    int helper(int i, int x1, int y1, int x2, int y2,string& word){
        if(i>=size)return 0;
        if(dp.find({i,x1,y1,x2,y2})!=dp.end())return dp[{i,x1,y1,x2,y2}];

        int dist = 1e5;
        int xd=coordinates[word[i]][0];
        int yd=coordinates[word[i]][1];
        //use finger 1
        if(x1==-1 && y1==-1){
            dist=min(dist,0+helper(i+1,xd,yd,x2,y2,word));
        }
        else{
            int change=abs(x1-xd)+abs(y1-yd);
            dist=min(dist , change+helper(i+1,xd,yd,x2,y2,word));
        }

        //use finger 2
        if(x2==-1 && y2==-1){
            dist=min(dist,0+helper(i+1,x1,y1,xd,yd,word));
        }
        else{
            int change=abs(x2-xd)+abs(y2-yd);
            dist=min(dist , change+helper(i+1,x1,y1,xd,yd,word));
        }

        return dp[{i,x1,y1,x2,y2}]=dist;

    }
    int minimumDistance(string word) {
        size=word.size();
        char ch='A';
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                coordinates[ch]={i,j};
                if(ch=='Z'){
                    break;
                }
                ch++;
            }
        }

        return helper(0,-1,-1,-1,-1,word);


    }
};