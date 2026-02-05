class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipe, vector<vector<string>>& ingredients, vector<string>& supplies) {

        map<string,vector<string>> adj;
        map<string,int> indeg;
        set<string> sup;
        for(int i=0;i<recipe.size();i++){
            for(auto it: ingredients[i]){
                adj[it].push_back(recipe[i]);
                if(indeg.find(it)==indeg.end())indeg[it]=0;
            }
            if(indeg.find(recipe[i])==indeg.end())indeg[recipe[i]]=ingredients[i].size();
            else indeg[recipe[i]]+=ingredients[i].size();
        }

        for(int i=0;i<supplies.size();i++){
            sup.insert(supplies[i]);
        }
        queue<string> q;
        vector<string> ans;
        for(auto it: indeg){
            if(it.second==0 && sup.find(it.first)!=sup.end())q.push(it.first);
        }

        while(!q.empty()){
            string s=q.front();
            if(sup.find(s)==sup.end())ans.push_back(s);
            q.pop();

            for(auto it: adj[s]){
                indeg[it]--;
                if(indeg[it]==0)q.push(it);
            }
        }

        return ans;
    }
};