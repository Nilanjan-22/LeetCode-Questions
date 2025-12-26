class Solution {
public:
    bool check(map<char,pair<int,int>>& hashmap){
        for(auto it: hashmap){
            if(it.second.first>it.second.second)return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        string ans=""; //will store the minimum substring (initially empty)

        map<char,pair<int,int>> hashmap; //stores the (need,present) of each character

        for(int i=0;i<t.size();i++){
            if(hashmap.find(t[i])==hashmap.end()){
                hashmap[t[i]].first=1;
                hashmap[t[i]].second=0;
            }
            else hashmap[t[i]].first++;
        }

        int l=0,r=0; //pointers for finding the window

        //in each movement we will check through the map to check if we found the ans
        int ml=-1,mr=-1,mini=-1,prevr=-1; //pointers of the minimum window and its size
        while(r<s.size() && l<=r){
            if(hashmap.find(s[r])!=hashmap.end() && r!=prevr){
                hashmap[s[r]].second++;
                prevr=r;
            }
            if(check(hashmap)){
                if(mini==-1){
                    mini=r-l+1;
                    ml=l;
                    mr=r;
                }
                else if(mini>r-l+1){
                    mini=r-l+1;
                    ml=l;
                    mr=r;
                }

                if(hashmap.find(s[l])!=hashmap.end())hashmap[s[l]].second--;
                l++;
            }
            else{
                r++;
            }
        }

        if(ml==-1)return ans;
        while(ml<=mr){
            ans.push_back(s[ml]);
            ml++;
        }

        return ans;
    }
};