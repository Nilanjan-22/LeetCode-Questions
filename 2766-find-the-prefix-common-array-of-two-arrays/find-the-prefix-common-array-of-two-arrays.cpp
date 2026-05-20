class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        set<int> st;
        vector<int> prefCommonArray(n);
        for(int i=0;i<n;i++){
            if(i==0)prefCommonArray[0]=0;
            else prefCommonArray[i]=prefCommonArray[i-1];

            
            if(st.find(A[i])!=st.end()){
                prefCommonArray[i]++;
            }
            else{
                st.insert(A[i]);
            }

            if(st.find(B[i])!=st.end()){

                prefCommonArray[i]++;
            }
            else{
                st.insert(B[i]);
            }

        }

        return prefCommonArray;
    }
};