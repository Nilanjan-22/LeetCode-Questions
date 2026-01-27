class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        map<int,int> mp;
        for(int i=0;i<row.size();i++){
            mp[row[i]]=i;
            // cout<<row[i]<<"->"<<mp[row[i]]<<" ";
        }
        int swaps=0;

        for(int i=0;i<row.size();i+=2){
            int c1=row[i];
            int c2=c1^1;
            int curr=row[i+1];
            // cout<<c2<<endl;
            if(c2!=row[i+1]){
                swaps++;
                swap(row[i+1],row[mp[c2]]);
                swap(mp[curr],mp[c2]);
            
            }
        }
        return swaps;        
    }
};