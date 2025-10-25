class Solution {
public:
    int totalMoney(int n) {
        vector<int> v;
        int s=0;
        for(int i=0;i<=7;i++){
            s+=i;
            v.push_back(s);
        }
        int ni=max(0,n/7-1);
        int mul=(ni*(ni+1))/2;

        return (n/7)*v[7] + mul*7 + v[n%7]+(n/7)*(n%7);
    }
};