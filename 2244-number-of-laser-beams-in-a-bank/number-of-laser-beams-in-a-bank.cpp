class Solution {
public:
    int cnt1s(string s){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')cnt++;
        }
        return cnt;
    }
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        vector<int> vec;
        for(int i=0;i<bank.size();i++){
            int cnt=cnt1s(bank[i]);
            if(cnt>0)vec.push_back(cnt);
        }
        if(vec.empty())return 0;
        for(int i=0;i<vec.size()-1;i++){
            ans+=vec[i]*vec[i+1];
        }

        return ans;

    }
};