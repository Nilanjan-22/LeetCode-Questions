class Solution {
public:
    string largestGoodInteger(string num) {
        string g="";
        char prev=num[0];
        int cnt=1;
        string temp="";
        temp.push_back(prev);
        for(int i=1;i<num.size();i++){
            if(prev==num[i]){
                cnt++;
                temp.push_back(prev);
                if(cnt==3){
                    g+=temp;
                }
            }
            else {
                cnt=1;
                temp="";
                prev=num[i];
                temp.push_back(prev);
            }
        }

        sort(g.begin(),g.end());
        int s=g.size();
        if(g=="")return g;
        return g.substr(s-3,3);

    }
};